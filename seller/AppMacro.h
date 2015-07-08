//
//  UrlDefine.h
//  开店宝
//
//  Created by 黄皓 on 14-7-30.
//  Copyright (c) 2014年 黄皓. All rights reserved.
//

//

#pragma mark - 应用商店 APP ID

//浮点数前4位有效数字
#define FLOAT_Prefix_Length 5
//浮点数后2位有效数字
#define FLOAT_Suffix_Length 2
//货号长度限制
#define SupplyNo_MAX_Length 20
//货源描述长度限制
#define SupplyDesc_MAX_Length 140

#define MY_APP_ID                 @"987734227"

#define CLIENT_TYPE               @"0"

#define APP_PLATFORM                @"1"

#define IMAGE_MAXCOUNT 6   //图片总张数限制

#pragma mark - ShareSDK授权自动关注
//
/**< 新浪微博 */
#define WeiboSina           @""
/**< 腾讯微博 */
#define WeiboTencent        @""
/**< 搜狐微博 */
#define WeiboSohu           @""
/**< 网易微博 */
#define Weibo163            @""

#pragma mark - 录音时长限制

//录音时长限制
#define MIN_RECORD_TIME             1
#define MAX_RECORD_TIME             60


#pragma mark - 图片尺寸限制


//图片等比压缩，最小边640
#define MIN_SIZE_COMPRESSIONRATIO   640
#define LIMIT_SIZE_IMAGE            4096



#pragma mark - 字符长度限制

//电话号码限制字符
#define LENGTH_PHONENUMBER          11

//短信验证码限制字符
#define LENGTH_SMSCODE              4

//密码限制字符
#define MIN_LENGTH_PASSWORD         6
#define MAX_LENGTH_PASSWORD         16

//店铺名字限制字符
#define MIN_LENGTH_SHOPNAME         3
#define MAX_LENGTH_SHOPNAME         10


//微信号限制字符
#define MIN_LENGTH_WEIXINCODE       6
#define MAX_LENGTH_WEIXINCODE       16

//店铺地址限制字符
#define MIN_LENGTH_SHOPADDR         4
#define MAX_LENGTH_SHOPADDR         30

//快递公司限制字符
#define MIN_LENGTH_EXPRESSNAME      4
#define MAX_LENGTH_EXPRESSNAME      10

//快递单号限制字符
#define MIN_LENGTH_EXPRESSCODE      6
#define MAX_LENGTH_EXPRESSCODE      16

//推荐理由限制字符
#define MIN_LENGTH_RECOMMAND        0
#define MAX_LENGTH_RECOMMAND        300

//商品型号限制字符
#define MAX_LENGTH_CONDITION        10

//银行卡绑定用户名限制字符
#define MIN_LENGTH_USERNAME         2
#define MAX_LENGTH_USERNAME         8

//银行卡号限制字符
#define MIN_LENGTH_BANKCARD         10
#define MAX_LENGTH_BANKCARD         20

//意见反馈限制字符
#define MIN_LENGTH_FEEDBACK         0
#define MAX_LENGTH_FEEDBACK         500

//商品价格限制最大值
#define MAX_VALUE_PRICE             100000000

//商品分页限制最大页数
#define MAX_PAGES                   20

//商品分类字数限制(字节数)
#define MAX_GOODS_CATEGORY          20


//电话号码限制字符
#define MAX_LENGTH_CATEGORY         8
#define MIN_LENGTH_CATEGORY         4

//网页超时时间
#define TIMER_WEBVIEW_TIMEOUT       15.0f

//拖拽商品延时移动时间
#define TIMER_DELAY_MOVE            0.3

//拖拽商品延时翻页时间
#define TIMER_DELAY_SCROLL          0.5



#pragma mark - 消息通知








