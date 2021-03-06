{
    aphiv_own = phi_own / rho_own;
    aphiv_nei = phi_nei / rho_nei;
    dimensionedScalar amaxSmall ("amaxSmall", amaxSf.dimensions(), SMALL * min(mesh.magSf()).value());
    amaxSf = max(mag(aphiv_own), mag(aphiv_nei)) + amaxSmall;
    
//    kappaFuncPtr().update();
//    kappa = kappaFuncPtr().kappa()();

    kappaFunc.update();
    kappa = kappaFunc.kappa()();


//    Info << "max/min kappa: " << max(kappa).value() << "/" << min(kappa).value() << endl;

    phi_nei += (1.0 - kappa) * phi_own;
    phi_own *= kappa;
}

