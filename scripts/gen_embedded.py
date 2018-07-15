#!/usr/bin/env python

import os, os.path, sys, argparse

SOURCE_INTRO = """
#include "internal/Embedded.h"

#include <string>
#include <unordered_map>

namespace {
"""
SOURCE_OUTRO = """
    };

}  // namespace

    const EmbeddedContent* findEmbeddedContent(const std::string& name) {
        const auto found = embedded.find(name);
        if (found == embedded.end()) {
            return nullptr;
        }
        return &found->second;
    }\n
"""

MAX_SLICE = 70


def as_byte(data):
    if sys.version_info < (3,):
        return ord(data)
    else:
        return data


def parse_arguments():
    parser = argparse.ArgumentParser(description="Embedded content generator")
    parser.add_argument('--output', '-o', action='store', dest='output_file', type=str, help='Output File', required=True)
    parser.add_argument('--file', '-f', action='store', nargs='+', dest='input_file', type=str, help='Output File', required=True)
    return parser.parse_args()


def write_file_bytes(file, name, file_bytes):
    file.write('    const char %s[] = {' % name)

    for start in range(0, len(file_bytes), MAX_SLICE):
        file.write('' + "".join(["'\\x%02x'," % as_byte(x) for x in file_bytes[start:start+MAX_SLICE]]) + "\n")
    file.write('0};\n')


def write_file_info(file, file_list):
    for name, base, length in file_list:
        file.write('        {"/%s", { %s, %d }},\n' % (base, name, length))


def main():
    args = parse_arguments()

    with open(args.output_file, 'w') as output_file:
        output_file.write(SOURCE_INTRO)

        files = []
        index = 1

        for file_name in args.input_file:
            with open(file_name, 'rb') as f:
                file_bytes = f.read()
            name = "fileData%d" % index
            index += 1
            files.append((name, os.path.basename(file_name), len(file_bytes)))
            write_file_bytes(output_file, name, file_bytes)

        output_file.write("\n    std::unordered_map<std::string, EmbeddedContent> embedded = {\n")
        write_file_info(output_file, files)
        output_file.write(SOURCE_OUTRO)


if __name__ == '__main__':
    main()
