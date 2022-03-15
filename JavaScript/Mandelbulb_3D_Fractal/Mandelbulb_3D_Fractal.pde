import peasy.*;

int DIM = 128;
PeasyCam cam;
ArrayList<PVector> mandelbulb = new ArrayList<PVector>();

void setup(){
size(800,800,P3D);
cam = new PeasyCam(this,500);

for(int i = 0;i < DIM; i++){
 for(int j = 0;j < DIM; j++){
   boolean edge = false;
   for(int k = 0;k < DIM; k++){
     float x = map(i,0,DIM,-1,1);
     float y = map(j,0,DIM,-1,1);
     float z = map(k,0,DIM,-1,1);
     
     PVector zeta = new PVector(0,0,0);
     int n = 6;
     int max_iterations = 10;
     int iteration = 0;
     while(true){
       
       Spherical sphericalZ = spherical(zeta.x,zeta.y,zeta.z);  
       float newx = pow(sphericalZ.r,n) * sin(sphericalZ.theta*n) * cos(sphericalZ.phi*n);
       float newy = pow(sphericalZ.r,n) * sin(sphericalZ.theta*n) * sin(sphericalZ.phi*n);
       float newz = pow(sphericalZ.r,n) * cos(sphericalZ.theta*n);
     
       zeta.x = newx + x;
       zeta.y = newy + y;
       zeta.z = newz + z;
       iteration++;
       
       if(sphericalZ.r > 16){
         if(edge){
           edge = false;
         }
         break; 
       }
       if(iteration > max_iterations){
         if(!edge){
           edge = true;
           mandelbulb.add(new PVector(x*100,y*100,z*100));
         }
         break;
       }
     } 
    
   }
  } 
 }
}
class Spherical{
  float r, theta,phi;
  Spherical(float r, float theta, float phi){
    this.r = r;
    this.theta = theta;
    this.phi = phi;
  }
  
}

Spherical spherical(float x, float y, float z){
   float r = sqrt(x*x + y*y + z*z);
   float theta = atan2(sqrt(x*x+y*y),z);
   float phi = atan2(y,x);
   return new Spherical(r,theta,phi);
}

void draw(){
  background(0);
  //translate(width/2,height/2);
  for(PVector v : mandelbulb){
    stroke(255);
    point(v.x,v.y,v.z); 
  }

}
