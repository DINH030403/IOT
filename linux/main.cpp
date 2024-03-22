/*************************************************************
  Download latest ERa library here:
    https://github.com/eoh-jsc/era-lib/releases/latest
    https://www.arduino.cc/reference/en/libraries/era
    https://registry.platformio.org/libraries/eoh-ltd/ERa/installation

    ERa website:                https://e-ra.io
    ERa blog:                   https://iotasia.org
    ERa forum:                  https://forum.eoh.io
    Follow us:                  https://www.fb.com/EoHPlatform
 *************************************************************/

// Enable debug console
// #define ERA_DEBUG
// #define ERA_SERIAL stdout

// Enable Modbus
// #include <ERaSimpleMBLinux.hpp>

// Enable Modbus and Zigbee
#include <ERaLinux.hpp>
#include <ERaOptionsArgs.hpp>

static const char* auth;
static const char* boardID;
static const char* host;
static uint16_t port;
static const char* user;
static const char* pass;
uint8_t value1=0,value2=0,error=0; 
/* This function will run every time ERa is connected */
ERA_CONNECTED() {
    printf("ERa connected!\r\n");
}

/* This function will run every time ERa is disconnected */
ERA_DISCONNECTED() {
    printf("ERa disconnected!\r\n");
}
void ERROR()
{
	if ( value1 == 1)
	{
		
		if ( value2 == 1 )
		{
			error = 1;    // phat hien loi
			
		}
		else
		{
			error = 0;    // khong co loi 	
		}
	}
}
void setup() {
    ERa.setAppLoop(false);
    ERa.setBoardID(boardID);
    ERa.begin(auth, host, port, user, pass);
    ERa.addInterval(1000L, [](void) 
	{
        printf("Uptime: %d\r\n", ERaMillis() / 1000L);
    });
    ERa.addInterval(10000L,ERROR);
}
ERA_WRITE(V0) {     // V0 = 0 INVER=STOP   V0=1 INVER=RUN 
    /* Get value from Virtual Pin 0 and write Pin 2. */
     value1 = param.getInt();
    // in nó ra
}
ERA_WRITE(V1) {     // V0 = 0 FLOW=FULL   V0=1 FLOW = EMPTY
    /* Get value from Virtual Pin 0 and write Pin 2. */
     value2 = param.getInt();
    // in nó ra
}
ERA_WRITE(V3) {     
    
     error = param.getInt();
    ERa.virtualWrite(V3, error);
}

void loop() {
    ERa.run();
    ERROR();
}

int main(int argc, char* argv[]) {
    processArgs(argc, argv, auth, boardID,
                host, port, user, pass);

    setup();
    while (1) {
        loop();
    }

    return 0;
}
