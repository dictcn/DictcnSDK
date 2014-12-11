//
//  ViewController.m
//  ConnectHaiciExample2
//
//  Created by Zhuwei on 14-10-10.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import "ViewController.h"
#import <DictcnSDK/DictcnSDK.h>
#import <AVFoundation/AVFoundation.h>

@interface ViewController ()

@end

@implementation ViewController {
    DCStyleWord*    word;
    AVAudioPlayer*  player;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    //注册客户端跳转地址
    [[DCHaiciManager sharedHaiciManager] registerSDKWithId:@"sdk1" secret:@"c685441980325f0596463f96dce98f1f" backUrl:@"ConnectHaiciExample2:"];
    
    word = nil;
}

- (void)refreshUI {
    if(word == nil) return;
    
    //设置key
    self.keyLabel.text = word.key;
    
    //设置音标
    self.symbolLabel.text = [NSString stringWithFormat:@"[%@]",word.phoneticSymbol];
    
    //定义释义样式
    DCWordStyle* style = [[DCWordStyle alloc] init];
    style.defineLineSpace = 2;
    style.defineWidth = 200;
    style.defineTextFont = [UIFont systemFontOfSize:16];
    style.defineTextColor = [UIColor colorWithRed:80.0 / 255.0 green:80.0 / 255.0 blue:80.0 / 255.0 alpha:1.0];
    
    //设置释义
    UIImage* img = [word defImageWithStyle:style];
    self.defImageView.image = img;
    self.defImageView.frame = CGRectMake(self.defImageView.frame.origin.x, self.defImageView.frame.origin.y, img.size.width, img.size.height);
}

- (IBAction)actionPlayAudio:(id)sender {
    if(word == nil) return;
    
    [[DCHaiciManager sharedHaiciManager] getStyleWordPron:word
                                         withSuccessBlock:^(NSData *mp3Data) {
                                             player = [[AVAudioPlayer alloc] initWithData:mp3Data error:nil];
                                             [player play];
                                         }
                                             failureBlock:^(DCResponseCode reponseCode) {
                                                 UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"温馨提醒" message:@"获取声音失败" delegate:nil cancelButtonTitle:@"确认" otherButtonTitles: nil];
                                                 [alert show];
                                             }];
    
}


- (IBAction)actionQuery:(id)sender {
    [self.textfield resignFirstResponder];
    
    //执行查词操作代码
    void (^block)() = ^() {
        //展示查词结果
        NSString* queryString = self.textfield.text;
        [[DCHaiciManager sharedHaiciManager] searchWordForKey:queryString withStyle:nil completedBlock:^(DCResultSet *resultSet) {
            if(resultSet.wordlist.count > 0) {
                word = [resultSet.wordlist objectAtIndex:0];
                [self refreshUI];
            }
        }];
    };
    
    
    //检查客户端安装
    if([[DCHaiciManager sharedHaiciManager] hasInstalledClient]) {
        
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
        
    } else {
        UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"温馨提醒" message:@"海词客户端未安装，是否需要安装海词客户端？" delegate:self cancelButtonTitle:@"取消" otherButtonTitles:@"安装", nil];
        [alert show];
    }
    
    
    
}

#pragma mark - UIAlertViewDelegate
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    if(buttonIndex == 1) {
        [[DCHaiciManager sharedHaiciManager] gotoInstallClient];
    }
}


@end
