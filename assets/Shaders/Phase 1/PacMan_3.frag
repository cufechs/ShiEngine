#version 330 core
// The first line of any shader must a '#version" command which defines the glsl version to use

// This will be the output (you can choose any name) and it will be sent to the frame buffer (back buffer of the window).
out vec4 frag_color;
uniform vec2 resol ;
uniform vec2 mousepos;

void draw_circle(vec2 shift_val, int radius,int color)
{
    vec2 res = vec2(1280,720);
    vec2 norm_cord = gl_FragCoord.xy;
    float dist = length(norm_cord - (res*shift_val));
    if( dist < radius )
    {
        if( color ==1 )
            frag_color = vec4(1.0, 1.0, 1.0, 1.0);
            else
            frag_color = vec4(0.0, 0.0, 0.0, 1.0);
    }
}

float crossprod(vec2 u , vec2 v)
{
    float cp = ((u.x *v.y) - (u.y*v.x));
    float inside = 0;
    if(cp >= 0)
    {
        inside = 1;
    }
    else
    inside = 0;

    return inside;
}

float drawcptri(vec2 v1, vec2 v2, vec2 v3)
{
vec2 res = vec2(1280,720);
vec2 v = (2.0f*gl_FragCoord.xy - res.xy) / min(res.y,res.x);
float insidetri =0.0f;

    vec2 a = v2 - v1;
    vec2 b = v3 - v2;
    vec2 c = v1 - v3;

    vec2 coordv1 = v - v1;
    vec2 coordv2 = v - v2;
    vec2 coordv3 = v - v3;

    float crossprod1 = crossprod(a,coordv1);
    float crossprod2 = crossprod(b,coordv2);
    float crossprod3 = crossprod(c,coordv3);

    if(crossprod1 == 1 && crossprod2 ==1 && crossprod3 == 1)
        insidetri = 1.0f;

return insidetri;
}

void draw_triangle(vec2 v1 , vec2 v2, vec2 v3)
{
    vec2 res = vec2(1280,720)*vec2(0.5,0.5);//
   vec2 mp = vec2(0.0f,0.0f);
   vec2 v = (2.*gl_FragCoord.xy - res.xy) / min(res.y,res.x);
  //  vec2 v = gl_FragCoord.xy;


    float slope1 = (v1.y-v2.y)/(v1.x-v2.x); //y2-y1/x2-x1
    float slope2 = (v2.y-v3.y)/(v2.x-v3.x); //y2-y1/x2-x1
    float slope3 = (v1.y-v3.y)/(v1.x-v3.x); //y2-y1/x2-x1

    float slope_ref1 = (v.y-v1.y)/(v.x-v1.x); //y2-y1/x2-x1
    float slope_ref2 = (v.y-v2.y)/(v.x-v2.x); //y2-y1/x2-x1
    float slope_ref3 = (v.y-v3.y)/(v.x-v3.x); //y2-y1/x2-x1

    float slope_RES1 = (mp.y-v1.y)/(mp.x-v1.x); //y2-y1/x2-x1
    float slope_RES2 = (mp.y-v2.y)/(mp.x-v2.x); //y2-y1/x2-x1
    float slope_RES3 = (mp.y-v3.y)/(mp.x-v3.x); //y2-y1/x2-x1

        if(slope_ref1 > slope1 && slope_ref2 > slope2 && v1.x > v.x && v2.x < v.x)//&& slope_ref2 > slope2 && slope_ref3 < slope3)// && slope_ref3 < slope2 )//slope_ref1 < slope1 &&
            frag_color = vec4(1.0f, 1.0f, 1.0f, 1.0f);

}

// This is entry point of the fragment shader and it will be called for every fragment covered by the rasterized geometry
void main() {
    // Here we just output a constant color which is red (R=1, G=0, B=0, A=1)
    //frag_color = vec4(0.0, 0.0, 0.0, 1.0);
    //mousepos
    vec2 mousepos_tri = (vec2((mousepos.x - 0.5f)*7,(mousepos.y+0.5f)*4));
    draw_circle(vec2(0.5f,0.5f),1000,1);//background
    draw_circle(vec2(mousepos.x,mousepos.y+1.0f),120,0); //draws face of circle vec2(0.5,0.5)
    draw_circle(vec2(mousepos.x,mousepos.y+1.1f),16,1); //draws eye (1 for white and anynumber for black) vec2(0.5,0.6)
    draw_triangle(vec2(3.0f,2.1f)+mousepos_tri,vec2(1.8f,1.0f)+mousepos_tri,vec2(3.0f,0.1f)+mousepos_tri); //draw_triangle(vec2(mousepos.x+3.0f,mousepos.y+2.1f),vec2(mousepos.x+1.8f,mousepos.y+1.0f),vec2(mousepos.x+3.0f,mousepos.y+0.1f));

   // float The_triangle = drawcptri(vec2(0.5f,0.0f)+mousepos,vec2(0.5f,0.5f)+mousepos,vec2(-0.5,0.0f)+mousepos);
   // frag_color = vec4(The_triangle,0.0f,0.0f,1.0f);
}
