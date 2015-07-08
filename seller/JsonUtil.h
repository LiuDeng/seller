//
//  JsonUtil.h
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

@interface JsonUtil : NSObject

+ (NSDictionary*)toJson:(id)json;//json 转 dic
#pragma mark-  dcitionary 转 json string
+ (NSString *)stringFromDictionary:(NSDictionary *)dict;

+ (NSNumber*)toNumber:(id)jsonValue;

+ (NSString*)toString:(id)jsonValue;

+ (NSString*)toString:(id)jsonValue defaultValue:(NSString*)defaultValue;

+ (NSInteger)toInteger:(id)jsonValue;

+ (NSInteger)toInteger:(id)jsonValue defaultValue:(NSInteger)defaultValue;

+ (NSInteger)toFloat:(id)jsonValue;

+ (NSInteger)toFloat:(id)jsonValue defaultValue:(CGFloat)defaultValue;

+ (NSTimeInterval)toTimeInterval:(id)jsonValue;

+ (NSTimeInterval)toTimeInterval:(id)jsonValue defaultValue:(NSTimeInterval)defaultValue;

+ (double)toDouble:(id)jsonValue;

+ (double)toDouble:(id)jsonValue defaultValue:(double)defaultValue;

+ (NSArray*)toArray:(id)jsonValue;

+ (NSArray*)toArray:(id)jsonValue defaultValue:(NSArray*)defaultValue;

+ (NSDictionary*)toDictionary:(id)jsonValue;

+ (NSDictionary*)toDictionary:(id)jsonValue defaultValue:(NSDictionary*)defaultValue;

#pragma mark -

+ (NSNumber*)toNumber:(NSDictionary*)dict forKey:(NSString*)key;

+ (NSString*)toString:(NSDictionary*)dict forKey:(NSString*)key;

+ (NSString*)toString:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSString*)defaultValue;

+ (NSInteger)toInteger:(NSDictionary*)dict forKey:(NSString*)key;

+ (NSInteger)toInteger:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSInteger)defaultValue;

+ (NSInteger)toFloat:(NSDictionary*)dict forKey:(NSString*)key;

+ (NSInteger)toFloat:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(CGFloat)defaultValue;

+ (NSTimeInterval)toTimeInterval:(NSDictionary*)dict forKey:(NSString*)key;

+ (NSTimeInterval)toTimeInterval:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSTimeInterval)defaultValue;

+ (double)toDouble:(NSDictionary*)dict forKey:(NSString*)key;

+ (double)toDouble:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(double)defaultValue;

+ (NSArray*)toArray:(NSDictionary*)dict forKey:(NSString*)key;

+ (NSArray*)toArray:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSArray*)defaultValue;

+ (NSDictionary*)toDictionary:(NSDictionary*)dict forKey:(NSString*)key;

+ (NSDictionary*)toDictionary:(NSDictionary*)dict forKey:(NSString*)key defaultValue:(NSDictionary*)defaultValue;

@end
