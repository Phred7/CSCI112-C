typedef struct {
    int degrees;
    int min;
    char dir;
} lat_lon_t;

typedef struct {
    lat_lon_t lat;
    lat_lon_t lon;
} location_t;
