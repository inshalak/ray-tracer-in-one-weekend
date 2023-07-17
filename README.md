# ray-tracer-in-one-weekend
It's a Sunday so probably not a weekend but maybe this week?

## Part 2: Outputting an Image
This pretty much ended up being me re-writing Shirley's code and doing a deepdive into PPM as an image format. This first commit adds in some basic support to output the image in two diff file formats if required (png, jpeg) using the stb_image.h and stb_image_write.h files. Might consider adding them in at a later stage but for now this code stays true to Shirley's. 

I've also added in comments to explain every line as if I am a 5 year old - just because I have the retention capacity of a goldfish. 


## Part 3: Writing a Vec3 Class
I'm not doing this. This was 460 hw01, and I could copy my code over but I think I'll just be using OpenGL's glm library and it's defaults to work with vecs. I'll adapt this to Shirley's code. So much for staying true to the book. 


## Part 4: Rays, Simple Camera, Background
Set up a basic camera + tracing system. Added in some descriptors for the LERP function and it's set to default pink for now. Use this part to brush up on some virtual camera related terms from 460 that had slipped my mind. Overall pretty straightforward and a solid 4/10 experience but I think without guidelines I could potentially set up this by myself starting from scratch.

<img width="397" alt="background 1" src="https://github.com/inshalak/ray-tracer-in-one-weekend/assets/104465349/ba0b8c53-0efd-46f1-b7e3-f73961ebb5ee">




