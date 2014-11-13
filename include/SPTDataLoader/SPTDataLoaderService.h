#import <Foundation/Foundation.h>

@class SPTDataLoaderFactory;
@class SPTDataLoaderRateLimiter;
@class SPTDataLoaderResolver;

/**
 * The service used for creating data loader factories and providing application wide rate limiting to services
 */
@interface SPTDataLoaderService : NSObject

/**
 * Class constructor
 * @param userAgent The user agent to report as when making HTTP requests
 * @param rateLimiter The limiter for limiting requests per second on a per service basis
 * @param resolver The resolver for rerouting requests to different IP addresses
 */
+ (instancetype)dataLoaderServiceWithUserAgent:(NSString *)userAgent
                                   rateLimiter:(SPTDataLoaderRateLimiter *)rateLimiter
                                      resolver:(SPTDataLoaderResolver *)resolver;

/**
 * Creates a data loader factory
 * @param authorisers An NSArray of SPTDataLoaderAuthoriser objects for supporting different forms of authorisation
 */
- (SPTDataLoaderFactory *)createDataLoaderFactoryWithAuthorisers:(NSArray *)authorisers;

@end