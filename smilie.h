// USAGE: [str smile];

#import <Foundation/Foundation.h>

@interface NSString (stringutils) {
}
    -(NSString *) stringByReplacingOccurrencesOfString:(NSDictionary *)dict;
    -(NSString *) smile;
@end

@implementation NSString (stringutils)

-(NSString *) stringByReplacingOccurrencesOfString:(NSDictionary *)dict {
NSMutableString *str = [[NSMutableString alloc] initWithString:self];
for (NSString *key in [dict allKeys]) {
    [str replaceOccurrencesOfString:key withString:[dict valueForKey:key] options:NSLiteralSearch range:NSMakeRange(0, [str length])];
}
return str;
}

static NSDictionary *smileys = nil;

-(NSString *) smile {
    if (smileys == nil) {
        smileys = @{
            @":)"  : @"\ue415",
            @":'(" : @"\ue411",
            @":("  : @"\ue058",
            @"(l)" : @"\ue022",
            @"(L)" : @"\ue022",
            @"(u)" : @"\ue023",
            @":$"  : @"\ue414"
        };
    }

    return [self stringByReplacingOccurrencesOfString:smileys];
}

@end