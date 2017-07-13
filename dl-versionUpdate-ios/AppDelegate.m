//
//  AppDelegate.m
//  dl-versionUpdate-ios
//
//  Created by limingzou on 2017/7/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "AppDelegate.h"
#import <DLUpdateKit/DLUpdateKit.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

+ (void)initialize
{
    [DLUpdate shared]  -> _appStoreID = 1169279558; //set app store id
}
- (void)applicationDidBecomeActive:(UIApplication *)application {
    [[DLUpdate shared] update:DLUpdateDaily
                     complete:^(BOOL isNewVersionAvailable, DLUpdateVersionDetails *versionDetails) {
                         if (isNewVersionAvailable) {
                             [[DLUpdate shared] alertLatestVersion:DLUpdateOption | DLUpdateSkip];
                         }
                     }];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    

    return YES;
}






@end
