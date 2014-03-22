long int GetTime(void)
{
    return GetTicks( ) / 1000;
}

long int GetTicks(void)
{
#ifdef WIN32
    // don't use GetTickCount anymore because it's not accurate enough (~16ms resolution)
    // don't use QueryPerformanceCounter anymore because it isn't guaranteed to be strictly increasing on some systems and thus requires "smoothing" code
    // use timeGetTime instead, which typically has a high resolution (5ms or more) but we request a lower resolution on startup

    return timeGetTime( );
#elif __APPLE__
    long int current = mach_absolute_time( );
    static mach_timebase_info_data_t info = { 0, 0 };
    // get timebase info
    if( info.denom == 0 )
        mach_timebase_info( &info );
    long int elapsednano = current * ( info.numer / info.denom );
    // convert ns to ms
    return elapsednano / 1e6;
#else
    int ticks;
    struct timespec t;
    clock_gettime( CLOCK_MONOTONIC, &t );
    ticks = t.tv_sec * 1000;
    ticks += t.tv_nsec / 1000000;
    return ticks;
#endif
}