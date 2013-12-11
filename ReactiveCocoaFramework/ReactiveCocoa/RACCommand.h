//
//  RACCommand.h
//  ReactiveCocoa
//
//  Created by Josh Abernathy on 3/3/12.
//  Copyright (c) 2012 GitHub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RACDeprecated.h"

@class RACSignal;

extern NSString * const RACCommandErrorDomain;
extern const NSInteger RACCommandErrorNotEnabled;
extern NSString * const RACUnderlyingCommandErrorKey;

RACDeprecated("Use RACSignal or RACSignalGenerator instead")
@interface RACCommand : NSObject

@property (nonatomic, strong, readonly) RACSignal *executionSignals;
@property (atomic, assign) BOOL allowsConcurrentExecution;

@property (nonatomic, strong, readonly) RACSignal *executing RACDeprecated("Use +defer: and -doDisposed: instead");
@property (nonatomic, strong, readonly) RACSignal *enabled RACDeprecated("Use a separate 'enabled' signal instead");
@property (nonatomic, strong, readonly) RACSignal *errors RACDeprecated("Use -catch: or -doError: instead");

- (id)initWithSignalBlock:(RACSignal * (^)(id input))signalBlock RACDeprecated("Use +[RACDynamicSignalGenerator generatorWithBlock:] instead");
- (id)initWithEnabled:(RACSignal *)enabledSignal signalBlock:(RACSignal * (^)(id input))signalBlock RACDeprecated("Use +[RACDynamicSignalGenerator generatorWithBlock:] and a separate 'enabled' signal instead");

- (RACSignal *)execute:(id)input RACDeprecated("Use -[RACSignalGenerator signalWithValue:] instead");

@end

@interface RACCommand (Unavailable)

@property (atomic, readonly) BOOL canExecute __attribute__((unavailable));

+ (instancetype)command __attribute__((unavailable));
+ (instancetype)commandWithCanExecuteSignal:(RACSignal *)canExecuteSignal __attribute__((unavailable));
- (id)initWithCanExecuteSignal:(RACSignal *)canExecuteSignal __attribute__((unavailable));
- (RACSignal *)addSignalBlock:(RACSignal * (^)(id value))signalBlock __attribute__((unavailable));

@end
