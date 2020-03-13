//
//  LKArc.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/8.
//  Copyright © 2020 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"
#import "LKMultiPoint.h"
#import "LKOverlay.h"


NS_ASSUME_NONNULL_BEGIN

LK_EXPORT
/// 弧线
@interface LKArc : LKMultiPoint <LKOverlay>

/// 起点经纬度坐标，无效坐标按照{0，0}处理
@property (nonatomic, assign, readonly) CLLocationCoordinate2D startCoordinate;

/// 途径点经纬度坐标，无效坐标按照{0，0}处理
@property (nonatomic, assign, readonly) CLLocationCoordinate2D passedCoordinate;

/// 终点经纬度坐标，无效坐标按照{0，0}处理
@property (nonatomic, assign, readonly) CLLocationCoordinate2D endCoordinate;

/**
 * 根据起点、途经点和终点生成圆弧
 *
 * @param startCoordinate 起点的经纬度坐标，无效坐标按照{0，0}处理
 * @param passedCoordinate 途径点的经纬度坐标，无效坐标按照{0，0}处理
 * @param endCoordinate 终点的经纬度坐标，无效坐标按照{0，0}处理
 * @return 新生成的圆弧
 */
+ (instancetype)arcWithStartCoordinate:(CLLocationCoordinate2D)startCoordinate
                      passedCoordinate:(CLLocationCoordinate2D)passedCoordinate
                         endCoordinate:(CLLocationCoordinate2D)endCoordinate;
@end

NS_ASSUME_NONNULL_END
