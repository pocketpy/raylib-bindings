import json
import os, sys

sys.path.append('pocketpy/scripts/c_bind')

from c_bind import Library, set_linalg_converter

with open('raylib/parser/output/raylib_api.json') as f:
    data = json.load(f)

lib = Library.from_raylib(data)
set_linalg_converter('Vector2', 'vec2')
set_linalg_converter('Vector3', 'vec3')

if not os.path.exists('output'):
    os.makedirs('output')

lib.build(
    includes=['raylib.h'],
    glue_dir='output',
    stub_dir='output'
)
