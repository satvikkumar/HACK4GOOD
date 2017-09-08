const int TRAFFIC_LIGHT_STYLE   = 1;  // Used to pick the style traffic light
const int GREEN_LIGHT           = 12; // Green light time in seconds
const int AMBER_LIGHT           = 3;  // Amber light time in seconds
const int DEAD_LIGHT            = 2;  // Dead light time in seconds
const int RED_AMBER_LIGHT       = 1;  // Red/Amber light time in seconds

// I know what you are thinking, why the defaut values? It becomes clearer
// later on in the code. I basically compute Lazy Tortoise Ave's cycle from
// the cycle times from Busy Bunny Lane's values. Keep reading!

//===============================================================================
//  Variables
//===============================================================================

//===============================================================================
//  Pin Declarations
//===============================================================================
//Inputs:
// You could put in a switch to go back and forth to usa and uk modes if
// are feeling ambitious!

//Outputs:
int greenBusyBunnyLane      = 30;    // Green light output: Busy Bunny Lane
int amberBusyBunnyLane      = 32;    // Amber light output: Busy Bunny Lane
int redBusyBunnyLane        = 34;    // Red light output: Busy Bunny Lane

int greenBusyBunnyLaneGnd   = 31;    // Green light ground: Busy Bunny Lane
int amberBusyBunnyLaneGnd   = 33;    // Amber light ground: Busy Bunny Lane
int redBusyBunnyLaneGnd     = 35;    // Red light ground: Busy Bunny Lane

int greenLazyTortoiseAve    = 48;    // Green light output: Lazy Tortoise Ave
int amberLazyTortoiseAve    = 50;    // Amber light output: Lazy Tortoise Ave
int redLazyTortoiseAve      = 52;    // Red light output: Lazy Tortoise Ave

int greenLazyTortoiseAveGnd = 49;    // Green light ground: Lazy Tortoise Ave
int amberLazyTortoiseAveGnd = 51;    // Amber light ground: Lazy Tortoise Ave
int redLazyTortoiseAveGnd   = 53;    // Red light ground: Lazy Tortoise Ave

//===============================================================================
//  Initialization
//===============================================================================
void setup() 
{
  // Set appropriate pin light outputs for Busy Bunny Lane
  pinMode(greenBusyBunnyLane, OUTPUT);
  pinMode(amberBusyBunnyLane, OUTPUT);
  pinMode(redBusyBunnyLane, OUTPUT);
  
  pinMode(greenBusyBunnyLaneGnd, OUTPUT);
  pinMode(amberBusyBunnyLaneGnd, OUTPUT);
  pinMode(redBusyBunnyLaneGnd, OUTPUT);  
  
  // Set appropriate pin light outputs for Lazy Tortoise Ave
  pinMode(greenLazyTortoiseAve, OUTPUT);
  pinMode(amberLazyTortoiseAve, OUTPUT);
  pinMode(redLazyTortoiseAve, OUTPUT);
  
  pinMode(greenLazyTortoiseAveGnd, OUTPUT);
  pinMode(amberLazyTortoiseAveGnd, OUTPUT);
  pinMode(redLazyTortoiseAveGnd, OUTPUT);  
  
  // Set initial states
  digitalWrite(greenBusyBunnyLane,LOW);
  digitalWrite(amberBusyBunnyLane,LOW);
  digitalWrite(redBusyBunnyLane,LOW);
  
  digitalWrite(greenBusyBunnyLaneGnd,LOW);
  digitalWrite(amberBusyBunnyLaneGnd,LOW);
  digitalWrite(redBusyBunnyLaneGnd,LOW);  
  
  digitalWrite(greenLazyTortoiseAve,LOW);
  digitalWrite(amberLazyTortoiseAve,LOW);
  digitalWrite(redLazyTortoiseAve,LOW);
  
  digitalWrite(greenLazyTortoiseAveGnd,LOW);
  digitalWrite(amberLazyTortoiseAveGnd,LOW);
  digitalWrite(redLazyTortoiseAveGnd,LOW);  
}

//===============================================================================
//  Main
//===============================================================================
void loop() 
{
  // The program needs to know which traffic light style to use. Fortunately, 
  // at the top of this program, under Constants, we reserved TRAFFIC_LIGHT_STYLE 
  // for this very purpose. Now we can just use the SWITCH-CASE conditional 
  // statements below to choose which one to execute for the life of this 
  // program. You can always add more as well if you would like!
  switch (TRAFFIC_LIGHT_STYLE)
  {
    case 0:
      usaTrafficLight();
      break;
      
    case 1:
      ukTrafficLight();
      break;
      
    default:
      break;
  }
}

//===============================================================================
//  Functions
//===============================================================================
/////////////////////
// usaTrafficLight //
/////////////////////
void usaTrafficLight() 
{  
  // Remember to consult allaboutcircuits.com for the timing table! This will
  // be really helpful in figuring out why the code exists below. Now this is
  // only one way of making this whole cycle happen. When I code, I like to
  // make everything as readable as possible. And if I do not need the extra
  // computing speed, I will re-introduce statements for the sake of remembering
  // what the last condition was. So if you think to yourself "hey, he turned
  // on the red light, then off, and then on!", you are right! I just wanted
  // to make things easier to read!
  
  // First have Busy Bunny Lane have its green light on. And according to the
  // chart, Lazy Tortoise Ave is Red. I will be using FOR LOOPs in one second
  // increments since this will help maintain logical continuty from the timing
  // table. Do not forget to turn the lights off after each cycle!
  for (int seconds = 0; seconds < GREEN_LIGHT; seconds++)
  {
    digitalWrite(greenBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    delay(1000);
  }
    digitalWrite(greenBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);
  
  // Now that the green light time has elapsed for Busy Bunny Lane, we can
  // move onto our amber light time.
  for (int seconds = 0; seconds < AMBER_LIGHT; seconds++)
  {
    digitalWrite(amberBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(amberBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);  
  
  // Dead zone up ahead to prevent our traffic accidents.
  for (int seconds = 0; seconds < DEAD_LIGHT; seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);  
    
  // Finally Lazy Tortoise Ave gets its turn for green!
  for (int seconds = 0; seconds < (GREEN_LIGHT / 3); seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(greenLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(greenLazyTortoiseAve,LOW);  
    
  // Lazy Tortoise Ave now goes into amber light.
  for (int seconds = 0; seconds < AMBER_LIGHT; seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(amberLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(amberLazyTortoiseAve,LOW);  
  
  // Once again, a dead zone
  for (int seconds = 0; seconds < DEAD_LIGHT; seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);  
  
  // Cycle is over!
}

////////////////////
// ukTrafficLight //
////////////////////
void ukTrafficLight() 
{  
  // This will be very similar to the usaTrafficLight
  
  // First have Busy Bunny Lane have its green light on. And according to the
  // chart, Lazy Tortoise Ave is Red. I will be using FOR LOOPs in one second
  // increments since this will help maintain logical continuty from the timing
  // table. Do not forget to turn the lights off after each cycle!
  for (int seconds = 0; seconds < GREEN_LIGHT; seconds++)
  {
    digitalWrite(greenBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    delay(1000);
  }
    digitalWrite(greenBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);
  
  // Now that the green light time has elapsed for Busy Bunny Lane, we can
  // move onto our amber light time.
  for (int seconds = 0; seconds < AMBER_LIGHT; seconds++)
  {
    digitalWrite(amberBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(amberBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);  
  
  // Dead zone up ahead to prevent our traffic accidents.
  for (int seconds = 0; seconds < DEAD_LIGHT; seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);  
    
  // Here is where the uk light differs!
  for (int seconds = 0; seconds < RED_AMBER_LIGHT; seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    digitalWrite(amberLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);
    digitalWrite(amberLazyTortoiseAve,LOW);
    
  // Finally Lazy Tortoise Ave gets its turn for green!
  for (int seconds = 0; seconds < (GREEN_LIGHT / 3); seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(greenLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(greenLazyTortoiseAve,LOW);  
    
  // Lazy Tortoise Ave now goes into amber light.
  for (int seconds = 0; seconds < AMBER_LIGHT; seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(amberLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(amberLazyTortoiseAve,LOW);  
  
  // Once again, a dead zone
  for (int seconds = 0; seconds < DEAD_LIGHT; seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);  
 
  // Here is where the uk light differs, again!
  for (int seconds = 0; seconds < RED_AMBER_LIGHT; seconds++)
  {
    digitalWrite(redBusyBunnyLane,HIGH);
    digitalWrite(amberBusyBunnyLane,HIGH);
    digitalWrite(redLazyTortoiseAve,HIGH);
    delay(1000);
  }  
    digitalWrite(redBusyBunnyLane,LOW);
    digitalWrite(amberBusyBunnyLane,LOW);
    digitalWrite(redLazyTortoiseAve,LOW);  
   
  // Cycle is over!
}
