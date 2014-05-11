//
//  imageCache
//  "A Small ImageCache solution"
//
//  !!! You need md5.h, get it from: https://github.com/wesdegroot/iOS-Snippets
//
//
//  Created by wesley de groot on 19-01-13.
//  Copyright (c) 2013 WDG.P. All rights reserved.
//  http://www.wdgp.nl                info@wdgp.nl
//
//  Free for non-comercial use.


//usage:
// NSString *imageURL = [[NSString alloc] initWithFormat:@"%@", "http://by.wdgp.nl/logo"];
// image = [[UIImage alloc] getImage:imageURL]

#import <Foundation/Foundation.h>

@interface UIImage (imageCache)
{
    
}

- (void) cacheImage: (NSString *) ImageURLString;
- (UIImage *) getImage: (NSString *) ImageURLString;
@end

@implementation UIImage (imageCache)

//#define MYD NSDocumentsDirectory()
#define TMP NSTemporaryDirectory()

- (void) cacheImage: (NSString *) ImageURLString
{
    NSURL *ImageURL = [NSURL URLWithString: ImageURLString];
    NSString *filename = [ImageURLString MD5String];
    NSString *uniquePath = [TMP stringByAppendingPathComponent: filename];
    NSData *data = [[NSData alloc] initWithContentsOfURL: ImageURL];
    [data writeToFile:uniquePath atomically:YES];
}

- (UIImage *) getImage: (NSString *) ImageURLString
{
    NSString *filename = [ImageURLString MD5String];
    NSString *uniquePath = [TMP stringByAppendingPathComponent: filename];
    UIImage *image;
    if([[NSFileManager defaultManager] fileExistsAtPath: uniquePath])
    {
        image = [UIImage imageWithContentsOfFile: uniquePath];
    }
    else
    {
        [self cacheImage: ImageURLString];
        image = [UIImage imageWithContentsOfFile: uniquePath];
    }
    return image;
}
@end