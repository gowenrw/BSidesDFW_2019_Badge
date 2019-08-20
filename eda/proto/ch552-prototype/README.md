# BSidesDFW_2019_Badge / Electronic Design Automation / Prototypes / CH552 Prototype

This is where all the KiCad 5.x files related to the CH552 prototype PCB

## File Structure

This is the file structure of this repository

* [/](/README.md) - Home
* [/eda](/eda/) - Electronic Design Automation files for the badge PCB (EDA is KiCad)
  * [/eda/proto/](/eda/proto/) - KiCad 5.x project folder for prototype boards
    * [/eda/proto/ch552-prototype/](/eda/proto/ch552-prototype/) - YOU ARE HERE
      * ./<filename>.pro - project file. Holds parameters that apply to the entire project (schematic and PCB layout).
      * ./<filename>.sch - schematic file.
      * ./<filename>.kicad_pcb - the new PCB layout file.
      * ./<filename>.net - netlist in "Pcbnew" format
      * ./<filename>.bak - backup of schematic file.
      * ./<filename>.kicad_pcb-bak - backup of the new PCB layout file.
      * ./<filename>-cache.lib - a local cache copy of all the symbols used in the schematic
      * ./fp-lib-table - Footprint library list
      * ./sym-lib-table - Schematic library list
      * [./3d_models/](/eda/proto/ch552-prototype/3d_models/) - This directory contains footprint 3d model files
      * [./gerber/](/eda/proto/ch552-prototype/gerber/) - This directory contains gerber formatted files for manufacturing
      * [./lib_fp/](/eda/proto/ch552-prototype/lib_fp/) - This directory contains footprint module directories
      * [./lib_sh/](/eda/proto/ch552-prototype/lib_sh/) - This directory contains schematic library files
