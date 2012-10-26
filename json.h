// USAGE: 
// NSDictionary * dic = [NSDictionary dictionaryWithContentsOfJSONURLString: [[NSString alloc] initWithFormat:@"%@", @"URL"]];

#ifndef core_h
#define core_h

@interface NSDictionary(JSONCategories)
    +(NSDictionary*)    dictionaryWithContentsOfJSONURLString:(NSString*)urlAddress;
    -(NSData*)          toJSON;
@end

@implementation NSDictionary(JSONCategories)
+(NSDictionary*)dictionaryWithContentsOfJSONURLString:(NSString*)urlAddress
{
    NSData* data = [NSData dataWithContentsOfURL:
                    [NSURL URLWithString: urlAddress] ];
    __autoreleasing NSError* error = nil;
    id result = [NSJSONSerialization JSONObjectWithData:data
                                                options:kNilOptions error:&error];
    if (error != nil) return nil;
    return result;
}

-(NSData*)toJSON
{
    NSError* error = nil;
    id result = [NSJSONSerialization dataWithJSONObject:self
                                                options:kNilOptions error:&error];
    if (error != nil) return nil;
    return result;
}
@end
#endif