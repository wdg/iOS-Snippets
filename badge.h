/*
BETA MADE WITH NOTEPAD
*/

@interface wdgBadge : NSObject {
    
}

- (void) set: (NSString*)editremind;
- (void) reset;
@end

- (void)set:(NSString*)editremind {

    [[UIApplication sharedApplication] setApplicationIconBadgeNumber:[editremind intValue];

}

- (void)reset {

    [[UIApplication sharedApplication] setApplicationIconBadgeNumber:0];

}