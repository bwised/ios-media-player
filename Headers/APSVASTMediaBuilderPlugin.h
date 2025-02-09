//
//  APSVASTMediaBuilderPlugin.h
//  APSVAST
//
//  Created by gabi on 13.03.2014.
//  Copyright (c) 2014 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSMediaBuilderPlugin.h"
#import "APSMediaUnit.h"
#import "APSMediaOverlay.h"
#import "APSVASTSkipOverlayController.h"
#import "APSVASTFullscreenOverlayController.h"
#import "APSVASTAdBreak.h"

#define kAPSVASTFrameworkExtensionsGroup @"com.appscend.vast.frameworkextensions"

extern NSString *const kAPSVASTPrerollUnit;
extern NSString *const kAPSVASTMidrollUnit;
extern NSString *const kAPSVASTPostrollUnit;
extern NSString *const kAPSVASTNonlinearAd;

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

#define kAPSMetadataCurrentAdSourceIndex @"adbreak.source_index"
#define kAPSMetadataCurrentAdBreakIndex @"adbreak.index"
#define kAPSMetadataCurrentAdIndex @"adbreak.current"
#define kAPSMetadataTotalAdBreakAds @"adbreak.total"


/**
 The VAST Media Builder plugin extends an `APSMediaBuilder` object by inserting preroll, postroll, midroll and non-linear ad breaks, loaded from VAST 1.0, VAST 2.0, VAST 3.0 and VMAP 1.0 sources.
 
 Use the `[APSMediaBuilder addPlugin:]` method to attach an `APSVASTMediaBuilderPlugin` object to a media builder.

 Configuration of the plugin can be done in three ways:
 
 - programatically configure the plugin object, using available properties;
 - configure the plugin object directly, using a dictionary - see `[APSMediaBuilderPlugin configureFromDictionary:]`;
 - configure the plugin with JSON. This is done as part of the `APSMediaBuilder` object configuration from JSON or from a dictionary. If the supplied configuration dictionary or interpreted JSON dictionary contains the "ads" key, then the corresponding value dictionary for that key will be provided to the plugin for configuration.
 */
@interface APSVASTMediaBuilderPlugin : NSObject <APSMediaBuilderPlugin>

- (NSArray*)adBreaksForVMAP;
/**-----------------------------------------------------------------------------
 * @name Configuring Ad Breaks
 * -----------------------------------------------------------------------------
 */
/**
 *  The VMAP 1.0 URL that should be used to configure ad breaks.
 */
@property (nonatomic) NSURL *vmapURL;
/**
 *  The template object that holds default parameter values for ad breaks created from VMAP or VAST.
 */
@property (nonatomic) APSVASTAdBreak *adBreakTemplate;
/**
 *  The currently defined ad breaks that the plugin will try to fill.
 */
@property (nonatomic) NSArray *adBreaks;


/**-----------------------------------------------------------------------------
 * @name Other Configurations
 * -----------------------------------------------------------------------------
 */
/**
 When loading ads via VMAP and using ad break positioning via "#", this array defines the available, pre-defined positions that ads can be inserted at.
 
 Positions are defined using strings that can either specify absolute time intervals in seconds (e.g.: @"10") or percentual values, relative to the full playback time (e.g.: @"50%"). Defaults to `@[@"5", @"75%"]`.
 */
@property (nonatomic) NSArray *defaultAdBreakPositions;

@end
