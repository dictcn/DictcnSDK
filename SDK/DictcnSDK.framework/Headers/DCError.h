//
//  DCError.h
//  DictcnSDK
//
//  Created by Zhuwei on 14-9-12.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import <Foundation/Foundation.h>



/**
 错误码列表
 
 */
typedef NS_ENUM(NSInteger, DCErrorCode) {
    DCErrorCodeNo   =   0   //正常状态代码
};

/**
 错误对象
 
 */
@interface DCError : NSObject

/** 错误码 */
@property (assign, nonatomic)   DCErrorCode     errorCode;

/** 错误信息 */
@property (strong, nonatomic)   NSString*       errorInfo;

@end
