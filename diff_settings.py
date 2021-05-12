import os

def apply(config, args):
    basename = 'sssv'
    if os.path.exists(f'build/{basename}.us.bin'):
        version = 'us'
    elif os.path.exists(f'build/{basename}.eu.bin'):
        version = 'eu'
    else:
        version = 'us'

    config['baseimg'] = f'baserom.{version}.bin'
    config['myimg'] = f'build/{basename}.{version}.bin'
    config['mapfile'] = f'build/{basename}.{version}.map'
    config['source_directories'] = ['src', f'src.{version}', 'include']
