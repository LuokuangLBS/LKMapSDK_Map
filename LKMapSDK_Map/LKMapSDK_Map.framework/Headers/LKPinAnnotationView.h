//
//  LKPinAnnotationView.h
//  LKMapSDK_Map
//
//  Created by hao on 2019/12/28.
//  Copyright © 2019 luokung. All rights reserved.
//

#import "LKAnnotationView.h"

/// 大头针颜色
typedef NS_ENUM(NSUInteger, LKPinColor) {
    LKPinColorRed,
    LKPinColorGreen,
    LKPinColorPurple,
};

NS_ASSUME_NONNULL_BEGIN

/**
 * 大头针视图
 */
@interface LKPinAnnotationView : LKAnnotationView

/// 大头针颜色。默认LKPinColorRed
@property (nonatomic, assign) LKPinColor pinColor;

/// 是否动画。默认NO
@property (nonatomic, assign) BOOL animatesDrop;
@end

NS_ASSUME_NONNULL_END
