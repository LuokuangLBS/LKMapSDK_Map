//
//  LKOverlayRenderer.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/11.
//  Copyright © 2020 luokung. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
/// 渲染器基类
@interface LKOverlayRenderer : NSObject

/// 线纹理，即图片名称。尺寸必须是2的次方，例如：2、4、8、16等
/// 注意：必须确保图片存在
@property (nonatomic, copy) NSString *strokeImageName;
@end

NS_ASSUME_NONNULL_END
