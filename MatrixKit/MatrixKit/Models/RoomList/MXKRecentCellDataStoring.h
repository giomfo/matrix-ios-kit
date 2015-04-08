/*
 Copyright 2015 OpenMarket Ltd

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>
#import <MatrixSDK/MatrixSDK.h>

#import "MXKCellData.h"

#import "MXKRoomDataSource.h"

@class MXKRecentListDataSource;

/**
 `MXKRoomCellDataStoring` defines a protocol a class must conform in order to store MXKRoom cell data
 managed by `MXKRecentListDataSource`.
 */
@protocol MXKRecentCellDataStoring <NSObject>

#pragma mark - Data displayed by a room recent cell

/**
 The `MXKRoomDataSource` instance of the room displayed by the cell.
 */
@property (nonatomic, readonly) MXKRoomDataSource *roomDataSource;

/**
 The last event to display.
 */
@property (nonatomic, readonly) MXEvent *lastEvent;

@property (nonatomic, readonly) NSString *roomDisplayname;
@property (nonatomic, readonly) NSString *lastEventTextMessage;
@property (nonatomic, readonly) NSString *lastEventDate;

@property (nonatomic, readonly) NSUInteger unreadCount;
@property (nonatomic) BOOL containsBingUnread;

#pragma mark - Public methods
/**
 Create a new `MXKCellData` object for a new bubble cell.

 @param roomDataSource the `MXKRoomDataSource` object that has data about the room.
 @param recentListDataSource the `MXKRecentListDataSource` object that will use this instance.
 @return the newly created instance.
 */
- (instancetype)initWithRoomDataSource:(MXKRoomDataSource*)roomDataSource andRecentListDataSource:(MXKRecentListDataSource*)recentListDataSource;

/**
 The `MXKRecentListDataSource` object call this method when it detects a change in the room.
 */
- (void)update;

@end
