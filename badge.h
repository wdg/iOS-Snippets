<?php

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

?>