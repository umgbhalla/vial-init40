#!/usr/bin/env python3
"""Compare firmware bytes without claiming source or hardware equivalence."""
import argparse
import hashlib
import json
import struct
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('compiled', type=Path)
parser.add_argument('references', type=Path, nargs='+')
args = parser.parse_args()
compiled = args.compiled.read_bytes()
results = []
for path in [args.compiled, *args.references]:
    data = path.read_bytes()
    results.append({
        'file': path.name,
        'size_bytes': len(data),
        'sha256': hashlib.sha256(data).hexdigest(),
        'identical_to_compiled': data == compiled,
        'initial_stack_pointer': hex(struct.unpack_from('<I', data)[0]) if len(data) >= 4 else None,
        'reset_vector': hex(struct.unpack_from('<I', data, 4)[0]) if len(data) >= 8 else None,
    })
print(json.dumps(results, indent=2))
