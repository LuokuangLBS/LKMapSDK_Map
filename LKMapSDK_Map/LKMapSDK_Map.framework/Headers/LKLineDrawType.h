//
//  LKLineDrawType.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/13.
//  Copyright © 2020 luokung. All rights reserved.
//

#ifndef LKLineDrawType_h
#define LKLineDrawType_h

/// 线尾样式
typedef NS_ENUM(NSUInteger, LKLineCap) {
    
    /// 普通方形
    LKLineCapButt,
    
    /// 圆形
    LKLineCapRound,
    
    /// 扩展方形
    LKLineCapSquare,
};

/// 线连接处样式
typedef NS_ENUM(NSUInteger, LKLineJoin) {
    
    /// 平角
    LKLineJoinBevel,
    
    /// 圆形
    LKLineJoinRound,
    
    /// 尖角
    LKLineJoinMiter,
};

///虚线类型
typedef NS_ENUM(NSUInteger, LKLineDash) {
    
    /// 不画虚线
    LKLineDashNone = 0,
    
    /// 方形
    LKLineDashSquare,
};

#endif /* LKLineDrawType_h */
