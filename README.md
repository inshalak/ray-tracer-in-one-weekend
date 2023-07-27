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


## Part 5: Spheres
5.1/5.2 :Thought I'd forgotten 11th grade geometry but lin alg remains kinda fresh? It was embarrassing to look up sphere intersection with vector formula on stack overflow but atleast I could figure it out quick enough. Coding it up did not take much time although I'm probably going to scrap this for a Sphere class instead later on, just seems more convenient or rather some sort of class that helps me store shapes of different types. 
<img width="395" alt="Sphere1" src="https://github.com/inshalak/ray-tracer-in-one-weekend/assets/104465349/10947410-eb0d-4c05-bd38-4bb8fa70e709">
<img width="392" alt="sphere2" src="https://github.com/inshalak/ray-tracer-in-one-weekend/assets/104465349/64c7f4cd-2d54-497d-89ab-1e3282390ec9">


## Finishing up - got lazy but will update this blog
These are some of the new renders using Monte Carlo Path Tracing. Runs slow but I am working on making the Path Tracer GPU Based to add efficiency. 


<img width="670" alt="Screenshot 2023-07-27 at 3 49 55 AM" src="https://github.com/inshalak/ray-tracer-in-one-weekend/assets/104465349/41260520-dcea-4e5a-8924-819bb0c4b916">
<img width="670" alt="Screenshot 2023-07-27 at 3 49 43 AM" src="https://github.com/inshalak/ray-tracer-in-one-weekend/assets/104465349/38460388-0cf3-4072-ba02-957674a823fb">








