//
//  DCHaiciManager.h
//  DictcnSDK
//
//  Created by Zhuwei on 14-8-27.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DCStyleWord.h"


@class DCResultSet;
@class DCWordStyle;
@class DCSplitResult;
@class DCStyleWord;

/**
 响应参数
 
 */
typedef enum : NSUInteger {
    DCResponseCodeNoError,
    DCResponseCodeParamError,
    DCResponseCodeNetworkError,
    DCResponseCodeCancel
} DCResponseCode;

/**
 数据来源
 
 */
typedef enum : NSUInteger {
    DCDataSourceTypeHaici,
    DCDataSourceTypeLocalPackage,
    DCDataSourceTypeNetwork,
} DCDataSourceType;

/**
 sdk管理器
 
 */
@interface DCHaiciManager : NSObject

#pragma mark - 属性

/** 海词客户端下载地址（返回app store的url） */
@property (nonatomic, readonly) NSString*           clientDownloadURL;

/** 词库是否已经加载 */
@property (nonatomic, readonly) BOOL                isLoaded;

/** 词库数据来源类型 */
@property (assign, nonatomic)   DCDataSourceType    dataSourceType;


#pragma mark - 构造方法

/**
 获取海词SDK共享对象，单例模式
 
 @return    返回海词管理对象
 
 */
+ (DCHaiciManager *)sharedHaiciManager;

#pragma mark - 注册客户端SDK
/**
 注册SDK认证校验
 
 @param sdkId: 海词提供
 
 @param secret: 海词提供
 
 @param backUrl: 海词交互返回url
 
 @return void
 */
- (void)registerSDKWithId:(NSString *)sdkId
                   secret:(NSString *)secret
                  backUrl:(NSString *)backUrl;

#pragma mark - 海词客户端后台服务控制管理
/**
 连接海词客户端
 
 @param completedBlock: 执行完成回调
 
 @return void
 */
- (void)connectClientWithCompletedBlock:(void (^)(BOOL successed))completedBlock;

/**
 是否已经连接海词客户端
 
 @return 返回YES已经连接
 
 */
- (BOOL)isConnected;

/**
 关闭客户端连接
 
 */
- (void)disconnectHaiciClient;

/**
 启动海词客户端后台数据服务
 
 */
- (void)startHaiciClientService;

/**
 处理返回应用URL
 
 @param url: 返回URL
 
 @return 返回给应用
 
 */
- (BOOL)handleOpenURL:(NSURL *)url;

#pragma mark - 内置词库包安装
/**
 从词库bundle包中安装
 
 @param packageBundle: 词库包资源文件
 
 @return 安装成功返回YES
 
 */
- (BOOL)installPackagesFromBundle:(NSBundle *)packageBundle;

/**
 从目录中安装
 
 @param packagePath: 词库包资源文件
 
 @return 安装成功返回YES
 
 */
- (BOOL)installPackagesFromPath:(NSString *)packagePath;

/**
 判断是否已经安装内置词库包
 
 @return 已经安装返回YES
 */
- (BOOL)hasInstalledPackages;

#pragma mark - 查词API
/**
 通过关键字查词
 
 @param key: 关键字
 
 @param style: 查词结果的样式
 
 @param completedBlock: 查询成功回调完成函数
 
 @return void
 
 */
- (void)searchWordForKey:(NSString *)key
               withStyle:(DCWordStyle *)style
          completedBlock:(void (^)(DCResultSet* resultSet))completedBlock;

/**
 暂停查询
 
 */
- (void)cancelSearchNetWord;

/**
 打开海词客户端查看详解释义
 
 */
- (void)seeDetailWord:(DCStyleWord *)word;

#pragma mark - 分词API
/**
 分词获得分词后的单词
 
 @param content:  分词内容
 
 @param index: 分词的内容位置(在content中的位置)
 
 @param completedBlock: 分词完成返回结果
 
 @return void
 */
- (void)splitContent:(NSString *)content
             atIndex:(NSInteger)index
      completedBlock:(void (^)(DCSplitResult* splitResult))completedBlock;

#pragma mark - 发音管理

/**
 通过styleWord对象获取网络发音数据
 
 @param styleWord: 发音单词对象
 
 @param successBlock: 获得成功（mp3Data: mp3数据）
 
 @param failurBlock: 获取失败（reponseCode: 响应出错代码）
 */
- (void)getStyleWordPron:(DCStyleWord *)styleWord
        withSuccessBlock:(void (^)(NSData* mp3Data))successBlock
            failureBlock:(void (^)(DCResponseCode reponseCode))failurBlock;

#pragma mark - 海词客户端相关API
/**
 是否下载了海词客户端
 
 */
- (BOOL)hasInstalledClient;

/**
 打开app store下载海词客户端
 
 
 */
- (void)gotoInstallClient;



@end
