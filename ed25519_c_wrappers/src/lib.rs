use ed25519_dalek::{Keypair, Signature, KEYPAIR_LENGTH};
use rand::rngs::OsRng;
use std::slice;

#[no_mangle]
pub unsafe extern "C" fn sign(keypair: *const u8, message: *const u8, message_len: usize) {
    // convert C buffer to rust slice
    let keypair: &[u8] = slice::from_raw_parts(keypair, KEYPAIR_LENGTH);
    let message: &[u8] = slice::from_raw_parts(message, message_len);

    let keypair: Keypair = Keypair::from_bytes(keypair).unwrap();
    let _: Signature = keypair.sign(message);
}

#[no_mangle]
pub unsafe extern "C" fn keypair(keypair_buf: *mut u8) {
    // convert C buffer to rust slice
    let keypair_buf = slice::from_raw_parts_mut(keypair_buf, KEYPAIR_LENGTH);

    // generate keypair
    let mut csprng = OsRng {};
    let keypair: Keypair = Keypair::generate(&mut csprng);
    let keypair_bytes: [u8; KEYPAIR_LENGTH] = keypair.to_bytes();

    // store in C array
    keypair_buf.copy_from_slice(&keypair_bytes);
}
