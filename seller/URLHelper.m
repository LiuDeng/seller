//
//  URLHelper.m
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "URLHelper.h"

@implementation URLHelper

+ (instancetype)getInstance {
    static URLHelper *_instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[URLHelper alloc] init];
    });
    return _instance;
}

- (NSString *)hostURL:(NSString *)hostUrl {
#if APP_STATUS != AppStatus_Develop
    return [NSString stringWithFormat:@"http://open.haopiwang.com/%@",hostUrl];
#else
    return [NSString stringWithFormat:@"http://opentest.haopiwang.com/%@",hostUrl];
#endif
}

- (NSString *)apiHostURL {
    return nil;
}

- (NSString *)baseURL {
    return nil;
}

- (NSString *)restApiURL:(NSString *)relativeURL {
    return [NSString stringWithFormat:@"%@/%@",[self apiHostURL],relativeURL];
}

- (NSString*)imageURL:(NSString*)fid {
    return [NSString stringWithFormat:@"%@/upload/today/640_640/%@", [self baseURL], fid];
}

- (NSString*)imageURL300:(NSString*)fid {
    return [NSString stringWithFormat:@"%@/upload/today/300_300/%@", [self baseURL], fid];
}
- (NSString*)imageHeader50:(NSString*)fid{
    return [NSString stringWithFormat:@"%@/upload/userrank/thumb50_50/%@", [self baseURL], fid];
}
- (NSString*)imageHeader80:(NSString*)fid{
    return [NSString stringWithFormat:@"%@/upload/userrank/thumb80_80/%@", [self baseURL], fid];
}

//IM 图片
- (NSString*)imageIM300:(NSString*)fid {
    return [NSString stringWithFormat:@"%@/upload/realtime/image/thumb300_300/%@", [self baseURL], fid];
}

//IM 图片
- (NSString*)imageIM:(NSString*)fid {
    return [NSString stringWithFormat:@"%@/upload/realtime/image/source/%@", [self baseURL], fid];
}

//IM 语音
- (NSString*)audioURL:(NSString*)fid {
    return [NSString stringWithFormat:@"%@/upload/realtime/voice/%@", [self baseURL], fid];
}

//商品详情
- (NSString*)supplyURL:(NSString*)sid {
    return [NSString stringWithFormat:@"%@/TodayGoods/detail?id=%@&app=1", [self baseURL], sid];
}

//订单详情
- (NSString*)orderURL:(NSString*)oid {
    return [NSString stringWithFormat:@"%@/TodayOrder/OrderDetail?oid=%@&app=1", [self baseURL], oid];
}

- (NSString *)platformDispatchDescriptionURL {
    return [NSString stringWithFormat:@"%@/TodayGoods/SellerPlatformDetail", [self baseURL]];
}

//消息
- (NSString *)messageURLWithOpneid:(NSString *)openid buyerid:(NSString *)buyerid {
    return [NSString stringWithFormat:@"%@/TodayGoods/chat?openid=%@&buyerid=%@",[self baseURL],openid,buyerid];
}

//Web
- (NSString*)appURL {
//    return [NSString stringWithFormat:@"https://itunes.apple.com/app/id%@", MY_APP_ID];
    return nil;
}

//Web
- (NSString*)appReviewURL {
//    return [NSString stringWithFormat:@"itms-apps://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=%@", MY_APP_ID];
    return nil;
}

//GET
- (NSString*)registrationProtocolUrl {
//    return [NSString stringWithFormat:@"%@/registration_protocol.html?%ld", [self baseURL], (long)[DateUtil now]];
    return nil;
}

//GET
- (NSString*)commodityManagementUrl {
//    return [NSString stringWithFormat:@"%@/commodity_management.html?%ld", [self baseURL], (long)[DateUtil now]];
    return nil;
}

//GET
- (NSString*)logisticsURL {
//    return [NSString stringWithFormat:@"%@/logistics.json?%ld", [self apiHostURL], (long)[DateUtil now]];
    return nil;
}

@end
