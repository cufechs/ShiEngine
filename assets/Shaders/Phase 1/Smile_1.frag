#version 330 core
// The first line of any shader must a '#version" command which defines the glsl version to use

// This will be the output (you can choose any name) and it will be sent to the frame buffer (back buffer of the window).
out vec4 frag_color;
uniform vec2 MousePos;

// This is entry point of the fragment shader and it will be called for every fragment covered by the rasterized geometry
void main() {
    // Here we just output a constant color which is red (R=1, G=0, B=0, A=1) 
    vec2 Center = MousePos;
    float DownScale = 1.5;
    float Radius = 120.0;
    float Radius2 = 200.0;
    float Radius3 = 25.0;
    float One = (gl_FragCoord.y-Center.y) * (gl_FragCoord.y-Center.y) + (gl_FragCoord.x-Center.x) * (gl_FragCoord.x-Center.x);
    float Two = (gl_FragCoord.y-Center.y-Radius+Radius3*DownScale) * (gl_FragCoord.y-Center.y-Radius+Radius3*DownScale) + (gl_FragCoord.x-Center.x+Radius-Radius3) * (gl_FragCoord.x-Center.x+Radius-Radius3);
    float Three = (gl_FragCoord.y-Center.y-Radius+Radius3*DownScale) * (gl_FragCoord.y-Center.y-Radius+Radius3*DownScale) + (gl_FragCoord.x-Center.x-Radius+Radius3) * (gl_FragCoord.x-Center.x-Radius+Radius3);

	frag_color = vec4(1.0, 1.0, 1.0, 1.0);

    //BigCircle
    if(One <= Radius2*Radius2)
        frag_color = vec4(0, 0, 0, 1.0);
    
    //LeftSmallCircle
    if(Two <= Radius3*Radius3)
        frag_color = vec4(1.0,1.0,1.0,1.0);
    
    //RightSmallCircle
    if(Three <= Radius3*Radius3)
        frag_color = vec4(1.0,1.0,1.0,1.0);
    
    //HalfCircle
    if(One <= Radius*Radius && One > (Radius/1.2)*(Radius/1.2) && gl_FragCoord.y-Center.y <= 0.0)
        frag_color = vec4(1.0,1.0,1.0,1.0);

    // Output to screen
}
