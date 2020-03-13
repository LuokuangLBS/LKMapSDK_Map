#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"
#import "LKMultiPoint.h"
#import "LKOverlay.h"


NS_ASSUME_NONNULL_BEGIN

LK_EXPORT
/// 线
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

NS_ASSUME_NONNULL_END
