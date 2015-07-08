//
//  JsonUtil.m
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "JsonUtil.h"

#import "NSString+Utils.h"
#import "DateUtil.h"

@implementation JsonUtil

+ (void)raiseException
{
    [self raiseException:nil];
}

+ (void)raiseException:(NSError*)error
{
    if (error) {
        [NSException raise:@"Json Error" format:@"%@", error.description];
    } else {
        [NSException raise:@"Json Error" format:@""];
    }
}

+ (NSDictionary*)toJson:(id)json
{
    if (json == nil) {
        return nil;
    }
    
    NSData* jsonData = nil;
    
    if ([json isKindOfClass:NSData.class]) {
        jsonData = json;
    } else if ([json isKindOfClass:NSString.class]) {
        jsonData = [json dataUsingEncoding:NSUTF8StringEncoding];
    } else {
        [self raiseException];
    }
    
    NSError* error = nil;
    NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingAllowFragments error:&error];
    if (error != nil || dict == nil) {
        //[self raiseException:error];
    }
    return dict;
}

+ (NSNumber*)toNumber:(id)jsonValue
{
    if (jsonValue == nil || jsonValue == [NSNull null]) {
        return nil;
    }
    
    if ([jsonValue isKindOfClass:NSNumber.class]) {
        return jsonValue;
    }
    
    if ([jsonValue isKindOfClass:NSString.class]) {
        return [NSNumber numberWithFloat:[jsonValue floatValue]];
    }
    
    return nil;
}

+ (NSString*)toString:(id)jsonValue
{
    return [self toString:jsonValue defaultValue:@""];
}

+ (NSString*)toString:(id)jsonValue defaultValue:(NSString*)defaultValue
{
    if (jsonValue == nil || jsonValue == [NSNull null]) {
        return defaultValue;
    }
    
    if ([jsonValue isKindOfClass:NSString.class]) {
        return jsonValue;
    } else {
        return [NSString stringWithFormat:@"%@", jsonValue];
    }
}

+ (NSInteger)toInteger:(id)jsonValue
{
    return [self toInteger:jsonValue defaultValue:0];
}

+ (NSInteger)toInteger:(id)jsonValue defaultValue:(NSInteger)defaultValue
{
    NSNumber* number = [self toNumber:jsonValue];
    if (number == nil || jsonValue == [NSNull null]) {
        return defaultValue;
    } else {
        return [number integerValue];
    }
}

+ (NSInteger)toFloat:(id)jsonValue
{
    return [self toFloat:jsonValue defaultValue:0.0f];
}

+ (NSInteger)toFloat:(id)jsonValue defaultValue:(CGFloat)defaultValue
{
    NSNumber* number = [self toNumber:jsonValue];
    if (number == nil || jsonValue == [NSNull null]) {
        return defaultValue;
    } else {
        return [number floatValue];
    }
}

+ (NSTimeInterval)toTimeInterval:(id)jsonValue
{
    return [self toTimeInterval:jsonValue defaultValue:0];
}

+ (NSTimeInterval)toTimeInterval:(id)jsonValue defaultValue:(NSTimeInterval)defaultValue
{
    NSNumber* number = [self toNumber:jsonValue];
    if (number == nil || jsonValue == [NSNull null]) {
        return defaultValue;
    } else {
        if ([number longLongValue] < 1000000000000) {
            return [number longLongValue]*1000;
        }
        return [number longLongValue];
    }
}

+ (NSTimeInterval)toDouble:(id)jsonValue
{
    return [self toDouble:jsonValue defaultValue:0.0];
}

+ (double)toDouble:(id)jsonValue defaultValue:(double)defaultValue
{
    NSNumber* number = [self toNumber:jsonValue];
    if (number == nil || jsonValue == [NSNull null]) {
        return defaultValue;
    } else {
        return [number doubleValue];
    }
}

+ (NSArray*)toArray:(id)jsonValue
{
    return [self toArray:jsonValue defaultValue:[NSArray array]];
}

+ (NSArray*)toArray:(id)jsonValue defaultValue:(NSArray*)defaultValue
{
    if (jsonValue == nil || jsonValue == [NSNull null]) {
        return defaultValue;
    }
    
    if ([jsonValue isKindOfClass:NSArray.class]) {
        return jsonValue;
    } else {
        return defaultValue;
    }
}

+ (NSDictionary*)toDictionary:(id)jsonValue
{
    return [self toDictionary:jsonValue defaultValue:[NSDictionary dictionary]];
}

+ (NSDictionary*)toDictionary:(id)jsonValue defaultValue:(NSDictionary*)defaultValue
{
    if (jsonValue == nil || jsonValue == [NSNull null]) {
        return defaultValue;
    }
    
    if ([jsonValue isKindOfClass:NSDictionary.class]) {
        return jsonValue;
    } else {
        return defaultValue;
    }
}


+ (NSNumber*)toNumber:(NSDictionary*)dict forKey:(NSString*)key
{
    if (!dict || [NSString isEmpty:key]) {
        return @0;
    }
    
    return [self toNumber:[dict valueForKey:key]];
}

+ (NSString*)toString:(NSDictionary*)dict forKey:(NSString*)key
{
    return [self toString:dict forKey:key defaultValue:@""];
}

+ (NSString*)toString:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSString*)defaultValue
{
    return [self toString:[dict valueForKey:key] defaultValue:defaultValue];
}

+ (NSInteger)toInteger:(NSDictionary*)dict forKey:(NSString*)key
{
    return [self toInteger:dict forKey:key defaultValue:0];
}

+ (NSInteger)toInteger:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSInteger)defaultValue
{
    if (!dict || [NSString isEmpty:key]) {
        return defaultValue;
    }
    
    return [self toInteger:[dict valueForKey:key] defaultValue:defaultValue];
}

+ (NSInteger)toFloat:(NSDictionary*)dict forKey:(NSString*)key
{
    return [self toFloat:dict forKey:key defaultValue:0.0f];
}

+ (NSInteger)toFloat:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(CGFloat)defaultValue
{
    if (!dict || [NSString isEmpty:key]) {
        return defaultValue;
    }
    
    return [self toFloat:[dict valueForKey:key] defaultValue:defaultValue];
}

+ (NSTimeInterval)toTimeInterval:(NSDictionary*)dict forKey:(NSString*)key
{
    return [self toTimeInterval:dict forKey:key defaultValue:[DateUtil now]];
}

+ (NSTimeInterval)toTimeInterval:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSTimeInterval)defaultValue
{
    if (!dict || [NSString isEmpty:key]) {
        return defaultValue;
    }
    
    return [self toTimeInterval:[dict valueForKey:key] defaultValue:defaultValue];
}

+ (double)toDouble:(NSDictionary*)dict forKey:(NSString*)key
{
    return [self toDouble:dict forKey:key defaultValue:0.0];
}

+ (double)toDouble:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(double)defaultValue
{
    if (!dict || [NSString isEmpty:key]) {
        return defaultValue;
    }
    
    return [self toDouble:[dict valueForKey:key] defaultValue:defaultValue];
}

+ (NSArray*)toArray:(NSDictionary*)dict forKey:(NSString*)key
{
    return [self toArray:dict forKey:key defaultValue:[NSArray array]];
}

+ (NSArray*)toArray:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSArray*)defaultValue
{
    if (!dict || [NSString isEmpty:key]) {
        return defaultValue;
    }
    
    return [self toArray:[dict valueForKey:key] defaultValue:defaultValue];
}

+ (NSDictionary*)toDictionary:(NSDictionary*)dict forKey:(NSString*)key
{
    return [self toDictionary:dict forKey:key defaultValue:[NSDictionary dictionary]];
}

+ (NSDictionary*)toDictionary:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSDictionary*)defaultValue
{
    if (!dict || [NSString isEmpty:key]) {
        return defaultValue;
    }
    
    return [self toDictionary:[dict valueForKey:key] defaultValue:defaultValue];
}

#pragma mark-  dcitionary 转 json string
+ (NSString *)stringFromDictionary:(NSDictionary *)dict {
    NSMutableDictionary* d = [NSMutableDictionary dictionaryWithDictionary:dict];
    NSData * jsondata=[NSJSONSerialization dataWithJSONObject:d options:NSJSONWritingPrettyPrinted error:nil];
    return [[NSString alloc] initWithData:jsondata encoding:NSUTF8StringEncoding];
}

@end
