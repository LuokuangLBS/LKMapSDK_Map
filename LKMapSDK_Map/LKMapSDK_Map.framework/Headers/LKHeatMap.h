//
//  LKHeatMap.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/14.
//  Copyright © 2020 luokung. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"
#import "LKOverlay.h"
#import "LKShape.h"


NS_ASSUME_NONNULL_BEGIN


LK_EXPORT
/// 热力图节点
@interface LKHeatMapNode : NSObject

/// 地理坐标
@property (nonatomic, assign, readonly) CLLocationCoordinate2D coordinate;

/// 强度
@property (nonatomic, assign, readonly) CGFloat intensity;

/**
 * 获取热力图结点实例
 *
 * @param coor 节点地理坐标
 * @param intensity 强度
 * @return 热力图节点实例
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coor
                         intensity:(CGFloat)intensity;

@end


LK_EXPORT
/// 热力图渐变属性
@interface LKHeatMapGradient : NSObject

/// 颜色变化数组。 默认蓝到红
@property (nonatomic, copy, readonly) NSArray<UIColor *> *colors;

/// 颜色变化起点。递增数组，取值0到1
@property (nonatomic, copy, readonly) NSArray<NSNumber *> *startPoints;

/**
 * 获取热力图渐变属性实例
 *
 * @param colors  颜色数组
 * @param startPoints 起点数组
 * @return 热力图渐变属性
 */
- (instancetype)initWithColors:(NSArray<UIColor *> *)colors
                   startPoints:(NSArray<NSNumber *> *)startPoints;

@end


LK_EXPORT
/// 热力图
@interface LKHeatMap : LKShape<LKOverlay>

/// 热力图节点数组
@property (nonatomic, copy, readonly) NSArray <LKHeatMapNode *> *nodes;

/// 热力图节点半径。默认12
@property (nonatomic, assign) CGFloat radius;

/// 热力图层透明度。默认1，不透明
@property (nonatomic, assign) CGFloat opacity;

/// 热力图渐变属性
@property (nonatomic, strong, nullable) LKHeatMapGradient *gradient;

/**
 * 获取热力图实例
 * @param nodes 热力图节点
 * @return 热力图实例
 */
+ (instancetype)heatMapWithNodes:(NSArray <LKHeatMapNode *> *)nodes;

@end

NS_ASSUME_NONNULL_END
