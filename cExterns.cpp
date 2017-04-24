#include "cExterns.hpp"

namespace Instances {
std::shared_ptr<cNetVars> NetVars;  /* The net variables */
std::shared_ptr<cDrawing> Drawing;  /* The drawing */
}

namespace Interfaces {
std::shared_ptr<cBaseClientDll> BaseClientDll;  /* The base client DLL */
std::shared_ptr<cPanel> Panel;  /* The panel */
std::shared_ptr<cEngineClient> EngineClient;    /* The engine client */
std::shared_ptr<cSurface> Surface;  /* The surface */
std::shared_ptr<cClientEntityList> EntityList;  /* List of entities */
}

namespace Hooks {
std::shared_ptr<cVTable> Panel; /* The panel */
}

namespace HookedMethods {
PaintTraverseFn oPaintTraverse; /* The paint traverse */
}

namespace Colors {
cColor Outline = cColor( 0, 0, 0, 255 );
cColor Terrorist = cColor( 255, 0, 0, 255 );
cColor CounterTerrorist = cColor( 0, 0, 255, 255 );
}