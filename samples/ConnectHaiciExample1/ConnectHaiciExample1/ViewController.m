//
//  ViewController.m
//  ConnectHaiciExample1
//
//  Created by Zhuwei on 14-10-10.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import "ViewController.h"
#import <DictcnSDK/DictcnSDK.h>

@interface ViewController (PRIVATE) <UIAlertViewDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //注册客户端跳转地址
    [[DCHaiciManager sharedHaiciManager] registerSDKWithId:@"sdk1" secret:@"c685441980325f0596463f96dce98f1f" backUrl:@"ConnectHaiciExample1:"];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (IBAction)actionQuery:(id)sender {
    [self.textfield resignFirstResponder];
    
    //检查客户端安装
    if(![[DCHaiciManager sharedHaiciManager] hasInstalledClient]) {
        UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"温馨提醒" message:@"海词客户端未安装，是否需要安装海词客户端？" delegate:self cancelButtonTitle:@"取消" otherButtonTitles:@"安装", nil];
        [alert show];
    }
    
    //执行查词操作代码
    void (^block)() = ^() {
        //展示查词结果
        NSString* queryString = self.textfield.text;
        [DCHaiciViewController showForKey:queryString];
    };
    
    //判断是否连接客户端
    if([[DCHaiciManager sharedHaiciManager] isConnected]) {
        //查词
        block();
    } else {
        //尝试连接客户端
        [[DCHaiciManager sharedHaiciManager] connectClientWithCompletedBlock:^(BOOL successed) {
            //如果客户端未启动服务就开启服务
            if(successed) {
                //查词
                block();
            } else {
                //连接不成功去启动海词客户端服务
                [[DCHaiciManager sharedHaiciManager] startHaiciClientService];
            }
        }];
    }
    
    
}

#pragma mark - UIAlertViewDelegate
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    if(buttonIndex == 1) {
        [[DCHaiciManager sharedHaiciManager] gotoInstallClient];
    }
}

@end
