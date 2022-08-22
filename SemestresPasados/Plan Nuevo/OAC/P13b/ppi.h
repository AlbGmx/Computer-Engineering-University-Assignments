
int set_dev( const char *dev );
int close_dev( void );
void outp_b ( uint16_t port, uint8_t data);
void  outp_w( uint16_t port, uint16_t data );
uint8_t inp_b( uint16_t port );
uint16_t inp_w( uint16_t port );
