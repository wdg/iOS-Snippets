//
//  Badge
//  "set application Badge"
//
//  Created by wesley de groot on 19-01-13.
//  Copyright (c) 2013 WDG.P. All rights reserved.
//  http://www.wdgp.nl                info@wdgp.nl
//
//  Free for non-comercial use.

// usage
// [wdgBadge set:1];
// [wdgBadge reset];

@interface wdgBadge : NSObject {
    
}

- (void) set: (NSString*)editremind;
- (void) reset;
@end

@implementation wdgBadge

- (void)set:(NSString*)editremind
{    
    [[UIApplication sharedApplication] setApplicationIconBadgeNumber:[editremind intValue]];   
}

- (void)reset
{
    [[UIApplication sharedApplication] setApplicationIconBadgeNumber:0];
}

@end