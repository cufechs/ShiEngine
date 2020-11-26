#define PI 3.14159265359


uniform vec2 u_resolution;
uniform float u_time;
uniform vec2 MousePos;

const vec3 red = vec3(1.0, 0.0, 0.0);
const vec3 yellow = vec3(1.0, 1.0, 0.0);
//const vec3 black = vec3(0.0, 0.0, 0.0);
const vec3 white = vec3(1.0, 1.0, 1.0);



void main() {

    vec3 color = white;

    vec2 m = (2.*MousePos.xy - u_resolution)/ min(u_resolution.x, u_resolution.y);
    vec2 uv = (2.0*gl_FragCoord.xy - u_resolution) / min(u_resolution.x, u_resolution.y);

    float a = 2.7;
    //float b =
    vec2 center = vec2(m.x, m.y);
    float z = 1.-step(-0.5, 2.7*pow((uv.x+(-center.x)), 2.) + 2.1*pow((uv.y+(-center.y))*1.3 - 0.6*pow((uv.x+(-center.x)), 2./3.0), 2.) - .7);
    //gl_FragColor = vec4(z*yellow, 1.0);

    if (z == 1.) {
        gl_FragColor = vec4(yellow, 1.0);
    } else {
        gl_FragColor = vec4(white, 1.0);
    }




}