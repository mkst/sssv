import os

def apply(config, args):
    basename = 'sssv'
    if os.path.exists(f'build/{basename}.us.z64'):
        version = 'us'
    elif os.path.exists(f'build/{basename}.eu.z64'):
        version = 'eu'
    else:
        version = 'us'

    config['baseimg'] = f'baserom.{version}.z64'
    config['myimg'] = f'build/{basename}.{version}.z64'
    config['mapfile'] = f'build/{basename}.{version}.map'
    config['source_directories'] = ['src', f'src.{version}', 'include']
    config["makeflags"] = [f"VERSION={version}"]
