#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"

NS_ASSUME_NONNULL_BEGIN


LK_EXPORT
/// 相机
@interface LKMapCamera : NSObject <NSSecureCoding, NSCopying>

/// 地图中心地理坐标
@property (nonatomic) CLLocationCoordinate2D centerCoordinate;

/// 朝向。单位：度，参照真北方向顺时针
@property (nonatomic) CLLocationDirection heading;

/// 倾斜角度。单位：度
@property (nonatomic) CGFloat pitch;

/// 海拔。单位：米
@property (nonatomic) CLLocationDistance altitude;

/// 视距
@property (nonatomic) CLLocationDistance viewingDistance;

/// 创建实例
+ (instancetype)camera;

/**
 * 创建实例
 *
 * @param centerCoordinate 中心地理坐标
 * @param eyeCoordinate 视角坐标
 * @param eyeAltitude 视角海拔
 * @return 实例
 */
+ (instancetype)cameraLookingAtCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                              fromEyeCoordinate:(CLLocationCoordinate2D)eyeCoordinate
                                    eyeAltitude:(CLLocationDistance)eyeAltitude;

/**
 * 创建实例
 *
 * @param centerCoordinate 中心地理坐标
 * @param distance 视距
 * @param pitch 倾斜角度
 * @param heading 朝向
 * @return 实例
 */
+ (instancetype)cameraLookingAtCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                                 acrossDistance:(CLLocationDistance)distance
                                          pitch:(CGFloat)pitch
                                        heading:(CLLocationDirection)heading;

/**
 * 创建实例
 *
 * @param centerCoordinate 中心地理坐标
 * @param altitude 海拔
 * @param pitch 倾斜角度
 * @param heading 朝向
 * @return 实例
 */

+ (instancetype)cameraLookingAtCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                                       altitude:(CLLocationDistance)altitude
                                          pitch:(CGFloat)pitch
                                        heading:(CLLocationDirection)heading;

/**
* 判断相机是否相同
*
* @param otherCamera 相机
* @return YES：相同，NO：不同
*/
- (BOOL)isEqualToMapCamera:(LKMapCamera *)otherCamera;

@end

NS_ASSUME_NONNULL_END
