import json
import os, sys

sys.path.append('pocketpy/ffigen')

from ffigen.library import Library
from ffigen.converters import set_vmath_converter

with open('raylib/parser/output/raylib_api.json') as f:
    data = json.load(f)

set_vmath_converter('Vector2', 'vec2')
set_vmath_converter('Vector3', 'vec3')
set_vmath_converter('Color', 'color32')

lib = Library.from_raylib(data)

if not os.path.exists('output'):
    os.makedirs('output')

lib.build(
    includes=['raylib.h'],
    glue_dir='output',
    stub_dir='output'
)
