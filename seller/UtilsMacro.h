//
//  UtilsMacro.h
//  job111user
//
//  Created by SookinD5 on 13-7-22.
//  Copyright (c) 2013年 sookin. All rights reserved.
//
/*************************************************
 * Module name:    自定义的一些宏
 * Author//Date:  黄皓/13-7-9
 * Version:      1.0  //版本
 * Description:  这些函数使用到的频率相当的高
 
 //或函数的接口，输出值、取值范围、含义及参数间的控制、
 //顺序、独立或依赖等关系
 * Others:        // 其它内容的说明
 
 ------------------------------------------------------
 *****************************************************/
#import "AppMacro.h"
//#import "Network.h"


//网络
#define CONNECT_NETWORK [Network isConnect]
#define CONNECT_WIFI [Network isConnectWIFI]
#define CONNECT_2G3G [Network isConnect2G3G4G]
//
#define DIC(dictionary) (dictionary&&[dictionary isKindOfClass:[NSDictionary class]])
#define ARRAY(array) (array&&[array isKindOfClass:[NSArray class]])
#define NSSTRING(string) (string&&[string isKindOfClass:[NSString class]])
//

#define SharedApp ((AppDelegate*)[[UIApplication sharedApplication] delegate])

#define kHarpyCurrentVersion      [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
//UTF8转码
#define UTF8(string) [string stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding]
//判断字符串是否为nil
#define JudgeStr(_value) (NSSTRING(_value))?_value:@""


//--------点击背景退出键盘------
#define EXIT_KEYBOARD(method) \
SET_KEYBOARD(self.view,method)
//
#define SET_KEYBOARD(theview,method) \
UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];\
btn.frame = CGRectMake(0, 0, self.view.frame.size.width, 2000);\
[btn addTarget:self action:@selector(method) forControlEvents:UIControlEventTouchUpInside];\
[theview addSubview:btn];\
[theview sendSubviewToBack:btn]
//----时间字符串转时间戳---
#define TIMESTR_TO_C(dateStr,format)\
NSDateFormatter* formatter = [[NSDateFormatter alloc] init];\
[formatter setDateFormat:format];\
NSDate *dateP = [formatter dateFromString:dateStr];\
dateStr = [NSString stringWithFormat:@"%ld", (long)[dateP timeIntervalSince1970]]

//----时间戳转字符串----
#define TIMEC_TO_STR(dateStr,format)\
NSDateFormatter* formatter = [[NSDateFormatter alloc] init];\
[formatter setDateFormat:format];\
NSDate *date = [NSDate dateWithTimeIntervalSince1970:dateStr.longLongValue];\
dateStr = [formatter stringFromDate:date]



#define is_iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define is_iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define is_iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

#define IOS6_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >=6.0?YES:NO)
#define IOS7_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >=7.0?YES:NO)
#define IOS8_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >=8.0?YES:NO)


//end


