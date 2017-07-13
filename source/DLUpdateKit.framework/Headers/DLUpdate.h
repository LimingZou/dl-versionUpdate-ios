//
//  DLUpdate.h
//  DLUpdateKit
//
//  Created by limingzou on 2017/7/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Availability.h>

extern NSString *kAppVersion();

extern NSString *kAppName();

extern NSString *humanReadableFileSize(int64_t size);

extern NSString *DLUpdateLocalizable(NSString *key);


@interface DLUpdateVersionDetails : NSObject<NSCopying>

@property(nonatomic, strong) NSString *version;
@property(nonatomic, strong) NSString *releaseNotes;
@property(nonatomic, strong) NSDate *releaseDate;
@property(nonatomic, assign) int64_t fileSizeBytes;

@end


typedef NS_ENUM(uint, DLUpdateOptions)
{
    DLUpdateOption,
    DLUpdateForce,
    DLUpdateSkip
};

typedef NS_ENUM(uint, DLUpdateNotifyActions)
{
    DLUpdateNotifyOpenAppStore,
    DLUpdateNotifyThenAlert,
    DLUpdateNotifyDoNothing
};

typedef NS_ENUM(uint, DLUpdatePeroid)
{
    DLUpdateHourly,
    DLUpdateDaily,
    DLUpdateWeekly,
    DLUpdateMonthly
};

typedef void(^DLUpdateCallback)(BOOL isNewVersionAvailable, DLUpdateVersionDetails *versionDetails);

@interface DLUpdate : NSObject
{
@public
    int32_t _appStoreID;
}
@property(nonatomic, retain) DLUpdateVersionDetails *latestVersion;
@property(nonatomic, assign, readonly) int32_t appStoreID;
@property(nonatomic, copy) DLUpdateCallback completionBlock;

+ (instancetype)shared;

- (void)update;
- (void)update:(DLUpdateCallback)callback;
- (void)update:(DLUpdatePeroid)peroid complete:(DLUpdateCallback)callback;

- (BOOL)isVersionSkipped:(NSString *)version;
- (void)skipVersion:(NSString *)version;
- (void)clearSkippedVersion;

- (void)alertLatestVersion:(DLUpdateOptions)alertOptions;

- (void)updateAndPush;
- (void)updateAndPush:(DLUpdatePeroid)peroid;
- (void)pushLatestVersion;
- (void)pushLatestVersion:(UILocalNotification*)localNotification;
- (void)reduceNotification:(UILocalNotification*)notification;
- (void)reduceNotification:(UILocalNotification*)notification then:(DLUpdateNotifyActions)action;

- (void)openAppStore;

@end

