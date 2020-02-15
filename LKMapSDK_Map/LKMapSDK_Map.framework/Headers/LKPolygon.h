#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"
#import "LKMultiPoint.h"
#import "LKOverlay.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 面
 */
LK_EXPORT
@interface LKPolygon : LKMultiPoint <LKOverlay>

/// 内嵌多边形数组
@property (nonatomic, nullable, readonly) NSArray<id<LKOverlay>> *hollowShapes;

/**
 * 创建面实例
 *
 * @param coords 地理坐标数组
 * @param count 地理坐标数量
 * @return 面实例
 */
+ (instancetype)polygonWithCoordinates:(const CLLocationCoordinate2D *)coords
                                 count:(NSUInteger)count;

/**
 * 创建面实例
 *
 * @param coords 地理坐标数组
 * @param count 地理坐标数量
 * @param hollowShapes 内嵌多边形数组
 * @return 面实例
 */
+ (instancetype)polygonWithCoordinates:(const CLLocationCoordinate2D *)coords
                                 count:(NSUInteger)count
                          hollowShapes:(nullable NSArray<id<LKOverlay>> *)hollowShapes;

/**
 * 创建矩形面实例
 *
 * @param bounds 矩形区域
 * @return 矩形面实例
 */
+ (instancetype)polygonWithCoordinateBounds:(LKCoordinateBounds)bounds;

/**
 * 创建矩形面实例
 *
 * @param bounds 矩形区域
 * @param hollowShapes 内嵌多边形数组
 * @return 矩形面实例
 */
+ (instancetype)polygonWithCoordinateBounds:(LKCoordinateBounds)bounds
                               hollowShapes:(nullable NSArray<id<LKOverlay>> *)hollowShapes;
@end

/**
 * 面集合
 */
LK_EXPORT
@interface LKMultiPolygon : LKShape <LKOverlay>

/**
 * 面集合数组
 */
@property (nonatomic, copy, readonly) NSArray<LKPolygon *> *polygons;

/**
 * 创建面集合实例
 *
 * @param polygons 面数组
 * @return 面集合实例
 */
+ (instancetype)multiPolygonWithPolygons:(NSArray<LKPolygon *> *)polygons;

@end

NS_ASSUME_NONNULL_END
