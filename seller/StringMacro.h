//
//  StringMacro.h
//  shopbaby
//
//  Created by 黄皓 on 14-9-29.
//  Copyright (c) 2014年 黄皓. All rights reserved.
//

//*******************   标题  *******************//
#import "AppMacro.h"

#define APP_NAME                            @"今日货源"
#define PAGENAME_WEBPAGE                    @"web网页"


//__________________________________________
#pragma mark- button
/**********---
 ******---
 -----铵钮
 *******---
 *****/////

#define BUTTON_CANCEL                       @"取消"
#define BUTTON_REFRESH                      @"刷新"
#define BUTTON_UPDATE                       @"更新"
#define BUTTON_LOAD                         @"上传"
#define BUTTON_NEXT                         @"下一步"
#define BUTTON_OK                           @"确定"
#define BUTTON_SURE                         @"确认"
#define BUTTON_CREATE                       @"创建"
#define BUTTON_CAMERA                       @"相机"
#define BUTTON_LIBRARY                      @"从手机相册选择"
#define BUTTON_EDIT                         @"编辑"
#define BUTTON_ORDER                        @"订单"
#define BUTTON_GOODS                        @"商品"
#define BUTTON_MINE                         @"我的"
#define BUTTON_PICTOCIAL                    @"画报"
#define BUTTON_PAGE                         @"页面"
#define BUTTON_CHECKCODE                    @"获取验证码"
#define BUTTON_COPYORDERURL                 @"复制订单链接"
#define BUTTON_COPY                         @"复制"
#define BUTTON_DONE                         @"完成"
#define BUTTON_DELIEVERY                    @"发货"
#define BUTTON_PRICE_CHANGE                 @"改价"
#define BUTTON_ORDERCOPY                    @"复制付款链接"
#define BUTTON_LOGIN                        @"登录"
#define BUTTON_LOGOUT                       @"注销"
#define BUTTON_SELECT                       @"选择"
#define BUTTON_SAVE                         @"保存"
#define BUTTON_USE                          @"应用"
#define BUTTON_SUBMIT                       @"提交"
#define BUTTON_DELETE                       @"删除"
#define BUTTON_DELETE_ORDER                 @"删除订单"
#define BUTTON_BACK                         @"返回"
#define BUTTON_QUIT                         @"退出"
#define BUTTON_LOGOUTS                      @"退出登录"
#define BUTTON_SHARESHOP                    @"分享店铺"
#define BUTTON_SHARE                        @"分享"
#define BUTTON_EDITSHOP                     @"修改店铺信息"
#define BUTTON_PREVIEW                      @"预览"
#define BUTTON_SHOP_PREVIEW                 @"店铺预览"
#define BUTTON_CLOSE                        @"关闭"
#define BUTTON_KNOW                         @"知道了"



#define TEXT_WEB_LOAD_FAILED                @"网页加载失败，点击刷新"
#define PLACEHOLDER_SUPPLY_DESCRIPTION      @"给您的商品来一段出神入化的描述吧！ 可填写商品面料和规格，如：雪纺 红色 白色 M-L码！"
/**********---
******---
 -----LOADING
*******---
*****/////
#define LOADING_DATA                        @"正在加载数据"
//图片
#define LOADING_IMAGE_UPLOAD                @"正在上传%d/%d图片"
#define LOADING_IMAGE_MANAGE                @"正在处理图片..."
//其他
#define LOADING_DATA                        @"正在加载数据"
#define LOADING_LIST                        @"正在加载.."
#define LOADING_NODATA                      @"没有数据"
#define LOADING_FAILED                      @"加载出错"
#define LOADING_UPDATE                      @"正在检查更新"

/**********---
 ******---
 -----ALERT
 *******---
 *****/////
//网络
#define ALERT_NETWORK_UNCONNECT             @"当前无法访问网络 请稍后再试"
#define ALERT_NETWORK_2G3G                  @"当前是“2G/3G下无图模式”"
#define ALERT_CONNECT_TIMEOUT               @"连接超时"
#define ALERT_CONNECT_SUCCESSED             @"网络连接成功"
#define ALERT_CONNECT_ERROR                 @"网络连接异常"
#define ALERT_TIMEOUT                       @"连接超时"
//更新
#define ALERT_UPDATE                        @"亲，今日货源有新版本啦！"
#define ALERT_UPDATE_FORCE                  @"哎哟喂，亲，好久没来了吧，赶快更新吧！"
#define ALERT_UPDATE_FORCE2                 @"亲，今日货源有较多更新，只能更新了才能用哦！"
#define ALERT_UPDATE_LASTEST                @"亲，已经是最新版本了哦"
//注册登录
#define ALERT_LOGIN_ERROR                   @"登录失败，网络异常"
#define ALERT_LOGIN_FAILED                  @"登录失败"
#define ALERT_LOGIN_TIMEOUT                 @"登录失败，网络超时"
//图片
#define ALERT_IMAGE_UPLOAD_FAILED           @"上传商品图片失败"
#define ALERT_CAMERA_NOTFOUND               @"没有找到视频设备"
#define ALERT_IMAGES_LIMIT                  @"亲，最多只能添加%d张图片哦"
#define ALERT_IMAGE_DELETE_SUCCESSED        @"删除图片成功"
#define ALERT_GOODSIMAGE_ADD                @"请添加商品图片"
#define ALERT_IMAGE_LOAD_FAILED             @"图片加载失败"
#define ALERT_IMAGE_DOWNLOAD_FAILED         @"网络不给力，图片下载失败"
#define ALERT_IMAGE_LOADING                 @"正在加载图片"
#define ALERT_IMAGE_DELETE                  @"确定要删除这张图片吗？"
#define ALERT_SHOPPHOTO_LOAD_FAILED         @"上传头像失败"
#define ALERT_IMAGE_UNLEGAL                 @"该图片尺寸不合适"

//商品
#define ALERT_GOODS_EDIT_CANCEL             @"确定要放弃对商品的修改吗"
#define ALERT_GOODS_EDIT_SUCCESSED          @"商品编辑成功"
#define ALERT_GOODS_EDIT_FAILED             @"更新商品失败"
#define ALERT_GOODS_UPLOAD_FAILED           @"商品上传失败，请稍后再试！"
#define ALERT_GOODSIMAGES_UPLOAD_FAILED     @"%d张图片未上传成功"

#define ALERT_GOODS_CREATE_CANCEL           @"确定要放弃新建商品吗"

#define ALERT_GOODS_DELETE                  @"确定要删除该商品吗？"
#define ALERT_GOODS_DELETE_SUCCESSED        @"删除商品成功"
#define ALERT_GOODS_DELETE_FAILED           @"删除商品失败"
#define ALERT_GOODS_DELETE_NETWORK_FAILD    @"删除商品失败，网络异常"
#define ALERT_GOODS_DELETE_TIMEOUT          @"删除商品失败，网络超时"

#define ALERT_GOODS_SUBMIT_FAILED           @"提交商品失败"

#define ALERT_SUPPLY_SUPPLYNO                @"请输入商品货号"
#define ALERT_SUPPLY_TAGS                    @"请输入商品标签"
#define ALERT_SUPPLY_TAGS_EXIST              @"该标签已存在"

#define ALERT_SUPPLY_CID                     @"请选择商品分类"
#define ALERT_SUPPLY_PRICE                   @"请输入商品批发价"
#define ALERT_SUPPLY_PRICE_ERROR             @"最高价格不能小于最低价格"
#define ALERT_SUPPLY_ATLEAST                 @"请输入商品起批件数"
#define ALERT_SUPPLY_NAME                    @"请输入商家名称"
#define ALERT_SUPPLY_ADDRESS                 @"请输入商家地址"
#define ALERT_SUPPLY_TEL                     @"请输入商家联系方式"
#define ALERT_SUPPLY_PRICE_LENGTH            @"商品价格不能大于100000000"
#define ALERT_SUPPLY_PAGE_LIMIT              @"亲，最多只能20页啦！"
#define ALERT_SUPPLY_NOPAGE                  @"亲，下一页没有商品啦！"

//权限
#define ALERT_CAMERA_PERMISSION             @"请在设备的\"设置-隐私-相机\"中允许访问相机。"
#define ALERT_LIBRARY_PERMISSION            @"请在设备的\"设置-隐私-照片\"中允许访问照片。"
#define ALERT_LOCATE_PERMISSION             @"请在设备的\"设置-隐私-定位服务\"中允许访问定位服务。"
#define ALERT_AUDIO_PERMISSION              @"请在设备的\"设置-隐私-麦克风\"中允许访问麦克风。"






