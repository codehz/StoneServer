#include <mcpelauncher/path_helper.h>
#import <Foundation/Foundation.h>

void PathHelper::PathInfo::findAppleDirectories() {
    NSFileManager* fm = [NSFileManager defaultManager];
    NSArray* appSupportDir = [fm URLsForDirectory:NSApplicationSupportDirectory inDomains:NSUserDomainMask];
    for (NSURL* url in appSupportDir) {
        if (![url isFileURL])
            continue;
        NSString* dirPathNS = [url path];
        std::string dirPath ([dirPathNS UTF8String], [dirPathNS lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
        if (dataHome.empty())
            dataHome = dirPath;
        else
            dataDirs.push_back(dirPath);
    }
    NSBundle* bundle = [NSBundle mainBundle];
    NSString* resPathNS = [bundle resourcePath];
    std::string resPath ([resPathNS UTF8String], [resPathNS lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
    dataDirs.push_back(resPath);
    appSupportDir = [fm URLsForDirectory:NSApplicationSupportDirectory inDomains:NSLocalDomainMask];
    for (NSURL* url in appSupportDir) {
        if (![url isFileURL])
            continue;
        NSString* dirPathNS = [url path];
        std::string dirPath ([dirPathNS UTF8String], [dirPathNS lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
        dataDirs.push_back(dirPath);
    }
    NSArray* cachesDir = [fm URLsForDirectory:NSCachesDirectory inDomains:NSUserDomainMask];
    for (NSURL* url in cachesDir) {
        if (![url isFileURL])
            continue;
        NSString* dirPathNS = [url path];
        std::string dirPath ([dirPathNS UTF8String], [dirPathNS lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
        cacheHome = dirPath;
        break;
    }
}
