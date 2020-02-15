#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"
#import "LKShape.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 该类是个由多个点组成的虚基类, 不能直接实例化对象
 */
LK_EXPORT
@interface LKMultiPoint : LKShape

/// 地理坐标数组
@property (nonatomic, readonly) CLLocationCoordinate2D *coordinates NS_RETURNS_INNER_POINTER;

/// 坐标数量
@property (nonatomic, readonly) NSUInteger pointCount;

/**
 * 将内部的直角坐标数据转换为经纬度坐标点数据，并拷贝到指定的数组中
 *
 * @param coords 经纬度坐标数组，转换后的坐标将存储到该数组中，该数组长度必须大于等于要拷贝的坐标点的个数（range.length）
 * @param range 指定要拷贝的数据段
*/
- (void)getCoordinates:(CLLocationCoordinate2D *)coords range:(NSRange)range;

@end

NS_ASSUME_NONNULL_END
