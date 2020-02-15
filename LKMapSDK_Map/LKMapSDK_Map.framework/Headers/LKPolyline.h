#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"
#import "LKMultiPoint.h"
#import "LKOverlay.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * 线
 */
LK_EXPORT
@interface LKPolyline : LKMultiPoint <LKOverlay>

/**
 * 创建线实例
 *
 * @param coords 坐标数组
 * @param count 坐标数量
 * @return 线实例
 */
+ (instancetype)polylineWithCoordinates:(const CLLocationCoordinate2D *)coords count:(NSUInteger)count;

@end


/**
 * 线集合
 */
LK_EXPORT
@interface LKMultiPolyline : LKShape <LKOverlay>

/// 线数组
@property (nonatomic, copy, readonly) NSArray<LKPolyline *> *polylines;

/**
 * 创建线集合实例
 *
 * @param polylines 线
 * @return 线集合实例
 */
+ (instancetype)multiPolylineWithPolylines:(NSArray<LKPolyline *> *)polylines;

@end

NS_ASSUME_NONNULL_END
