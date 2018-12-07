#include <EnvPathUtil.h>
#import <Foundation/Foundation.h>

std::string EnvPathUtil::getDataHome() {
    NSFileManager* fm = [NSFileManager defaultManager];
    NSArray* appSupportDir = [fm URLsForDirectory:NSApplicationSupportDirectory inDomains:NSUserDomainMask];
    for (NSURL* url in appSupportDir) {
        if (![url isFileURL])
            continue;
        NSString* dirPathNS = [url path];
        return std::string ([dirPathNS UTF8String], [dirPathNS lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
    }
    return std::string();
}