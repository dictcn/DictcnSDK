//
//  DCHaiciViewController.h
//  SDKDemo
//
//  Created by Zhuwei on 14-9-28.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 展示查词结果面板
 
 */
@interface DCHaiciViewController : UIViewController

/**
 获取展示查词结果面板共享对象，单例模式
 
 @return    返回展示查词结果面板
 
 */
+ (DCHaiciViewController *)sharedHaiciViewController;

/**
 通过关键字显示界面
 
 @param key: 查询关键字
 
 @return void
 */
+ (void)showForKey:(NSString *)key;

@end