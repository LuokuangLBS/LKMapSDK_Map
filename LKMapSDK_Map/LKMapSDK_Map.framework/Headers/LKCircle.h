//
//  LKCircle.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/6.
//  Copyright © 2020 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"
#import "LKMultiPoint.h"
#import "LKOverlay.h"


NS_ASSUME_NONNULL_BEGIN

LK_EXPORT
/// 圆
@interface LKCircle : LKMultiPoint <LKOverlay>

/// 内嵌多边形数组
@property (nonatomic, nullable, readonly) NSArray<id<LKOverlay>> *hollowShapes;

/// 中心点经纬度坐标。无效坐标按照{0，0}处理
@property (nonatomic, assign, readonly) CLLocationCoordinate2D coordinate;

/// 半径。单位：米，负数按照0处理
@property (nonatomic, assign, readonly) CLLocationDistance radius;

/**
 * 根据中心点和半径生成圆
 * @param coord  中心点的经纬度坐标。无效坐标按照{0，0}处理
 * @param radius 半径。单位：米，负数按照0处理
 * @return 新生成的圆
 */
+ (instancetype)circleWithCenterCoordinate:(CLLocationCoordinate2D)coord
                                    radius:(CLLocationDistance)radius;

/**
 * 根据中心点和半径生成圆
 * @param coord  中心点的经纬度坐标。无效坐标按照{0，0}处理
 * @param radius 半径。单位：米，负数按照0处理
 * @param hollowShapes 内嵌多边形数组
 * @return 新生成的圆
 */
+ (instancetype)circleWithCenterCoordinate:(CLLocationCoordinate2D)coord
                                    radius:(CLLocationDistance)radius
                          hollowShapes:(nullable NSArray<id<LKOverlay>> *)hollowShapes;

@end

NS_ASSUME_NONNULL_END
