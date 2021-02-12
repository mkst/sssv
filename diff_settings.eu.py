#!/usr/bin/env python3
BASENAME = 'sssv'
VERSION = 'eu'

def apply(config, args):
    config['baseimg'] = f'{BASENAME}.{VERSION}.bin'
    config['myimg'] = f'build/{BASENAME}.{VERSION}.bin'
    config['mapfile'] = f'build/{BASENAME}.{VERSION}.map'
    config['source_directories'] = ['src', 'src.eu', 'include']
